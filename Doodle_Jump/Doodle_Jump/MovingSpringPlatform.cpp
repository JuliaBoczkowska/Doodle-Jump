#include "MovingSpringPlatform.h"

#include "Constants.h"
#include "Player.h"


MovingSpringPlatform::MovingSpringPlatform(TextureHolder* textureHolder):
Platform(textureHolder),
MovingPlatform(textureHolder),
spring(textureHolder)
{
	spring.setSpringPosition(sprite.getPosition());
}

void MovingSpringPlatform::onCollision(Player& player)
{
	if(spring.springCollision(player))
		player.allowJump();
	else
		player.allowJump();
}

void MovingSpringPlatform::render(sf::RenderWindow* window) const
{
	window->draw(sprite);
	spring.render(window);
}

void MovingSpringPlatform::update(const float& dt)
{
	MovingPlatform::update(dt);
	spring.setSpringPosition(sprite.getPosition());
}
