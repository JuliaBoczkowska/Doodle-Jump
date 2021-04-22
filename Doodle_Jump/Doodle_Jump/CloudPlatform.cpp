#include "CloudPlatform.h"
#include "Player.h"


CloudPlatform::CloudPlatform(TextureHolder* textureHolder):
Platform(textureHolder),
DefaultPlatform(textureHolder),
disappear(false)
{
	sprite.setTexture(textureHolder->get("CLOUD"));
}

void CloudPlatform::onCollision(Player& player)
{
	if(!disappear)
	{
		player.allowJump();
		disappear = true;
	}
		
}

void CloudPlatform::render(sf::RenderWindow* window) const
{
	if (!disappear)
		window->draw(sprite);
}

