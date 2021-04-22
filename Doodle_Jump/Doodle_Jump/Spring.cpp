#include "Spring.h"
#include "Player.h"

Spring::Spring(TextureHolder* textureHolder) :
textureHolder(*textureHolder)
{
	sprite.setTexture(this->textureHolder.get("SPRING"));
} 

bool Spring::springCollision(Player& player)
{
	const auto offset = 6.0f;
	
	if (player.getVelocity() > 0
		&&
		player.sprite.getTransform().transformRect(player.rect).left + player.sprite.getTransform().transformRect(player.rect).width > getX() - offset
		&&
		player.sprite.getTransform().transformRect(player.rect).left  < getWidth() + offset
		&&
		player.sprite.getTransform().transformRect(player.rect).height + player.sprite.getTransform().transformRect(player.rect).top > getY()
		&&
		player.sprite.getTransform().transformRect(player.rect).height + player.sprite.getTransform().transformRect(player.rect).top < getHeight() + 20)
	{
		bouncePlayer(player);
		return true;
	}
	return false;
}


void Spring::bouncePlayer(Player& player)
{
	sprite.setTexture(textureHolder.get("SPRING_BROKEN"));
	player.jumpHeight = 4 * JUMP_HEIGHT;
}


void Spring::setSpringPosition(const sf::Vector2f& platformPos)
{
	sprite.setPosition(platformPos.x + getLocalWidth() / 2 + 4.f, platformPos.y - getLocalHeight() * 0.7f);
}

void Spring::render(sf::RenderWindow* window) const
{
	window->draw(sprite);
}

