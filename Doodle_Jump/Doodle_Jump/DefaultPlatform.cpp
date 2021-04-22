#include "DefaultPlatform.h"

#include "Player.h"

DefaultPlatform::DefaultPlatform(TextureHolder* textureHolder) : Platform(textureHolder)
{
	sprite.setTexture(textureHolder->get("DEFAULT"));
}

void DefaultPlatform::onCollision(Player& player) { player.allowJump(); }

void DefaultPlatform::update(const float& dt) {}
