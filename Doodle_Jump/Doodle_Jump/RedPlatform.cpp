#include "RedPlatform.h"
#include "Player.h"

RedPlatform::RedPlatform(TextureHolder* textureHolder):
Platform(textureHolder),
DefaultPlatform(textureHolder),
textureHolder(*textureHolder),
isBroken(false)
{
	sprite.setTexture(textureHolder->get("RED"));
}

void RedPlatform::update(const float& dt)
{
	if (isBroken)
		sprite.move(sf::Vector2f(0.f, 17.f));
}

void RedPlatform::onCollision(Player& player)
{
	breakPlatform();
}

void RedPlatform::breakPlatform()
{
	sprite.setTexture(textureHolder.get("RED_BROKEN"));
	isBroken = true;
}
