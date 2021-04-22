#include "SpringPlatform.h"
#include "Player.h"

SpringPlatform::SpringPlatform(TextureHolder* textureHolder) :
	Platform(textureHolder),
	DefaultPlatform(textureHolder),
	spring(textureHolder)
{
	spring.setSpringPosition(sprite.getPosition());
}

void SpringPlatform::onCollision(Player& player)
{
	spring.springCollision(player);

	player.allowJump();
}

void SpringPlatform::render(sf::RenderWindow* window) const
{
	window->draw(sprite);
	spring.render(window);
}
