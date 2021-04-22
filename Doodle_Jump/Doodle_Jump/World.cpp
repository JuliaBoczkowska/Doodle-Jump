#include "World.h"
#include <mutex>

std::once_flag onceFlag;

World::World(const std::shared_ptr<EssentialData>& data) :
	data(data),
	player(data->textureHolder),
	platformGenerator(data->textureHolder)
{
	loadTextures();
	spawnPlatforms();
}

void World::detectCollision()
{
	for (auto& platform : platforms)
	{
		if (player.getVelocity() > 0
			&&
			player.sprite.getTransform().transformRect(player.rect).left + player.sprite.getTransform().transformRect(player.rect).width > platform->getX()
			&&
			player.sprite.getTransform().transformRect(player.rect).left < platform->getWidth()
			&&
			player.sprite.getTransform().transformRect(player.rect).height + player.sprite.getTransform().transformRect(player.rect).top > platform->getY()
			&&
			player.sprite.getTransform().transformRect(player.rect).height + player.sprite.getTransform().transformRect(player.rect).top < platform->getHeight())
		{
			platform->onCollision(player);
			//std::call_once(onceFlag, std::mem_fn(&Player::endFirstMove), player);
			player.firstMove = false;
		}
	}
}

void World::update(const float& dt)
{
	//If platforms are out of view, erase them
	erasePlatforms();
	
	//Detect collision between player and platform
	detectCollision();

	//Spawn platforms
	spawnPlatforms();

	//Updates player movement
	player.update(dt, View::getView().getSize().y - 360);

	//Updates position of the platforms
	for (auto& platform : platforms)
		platform->update(dt);

	//Increasing the result
	score.update(player, platforms);

	//Follow the player jumping
	view.followPlayer(player.getSprite());
}

void World::erasePlatforms()
{
	platformGenerator.erasePlatforms(platforms, View::getBottomEdge().y);
}

void World::render()
{
	//Set current view of the camera
	data->window->setView(View::getView());

	//Follow the player position
	background.setPosition(View::getTopEdge());

	score.setPosition(View::getTopEdge());

	//Render background
	data->window->draw(background);

	//Render platforms
	for (auto& platform : platforms)
		platform->render(data->window);

	//Render objects to screen
	player.render(data->window);
	score.render(data->window);
}

void World::loadTextures()
{
	background.setTexture(data->textureHolder->get("BACKGROUND"));
}

bool World::gameOver() const
{
	if (player.getY() > View::getView().getCenter().y + (View::getView().getSize().y / 2)) //bottom
	{
		score.setHighScore();
		return true;
	}
	return false;
}

void World::spawnPlatforms()
{
	platformGenerator.spawnPlatforms(platforms, View::getTopEdge().y, score.getCurrentScore(), true);
}
