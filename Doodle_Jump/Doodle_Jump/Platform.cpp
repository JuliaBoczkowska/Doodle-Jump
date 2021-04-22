#include "Platform.h"

Platform::Platform(TextureHolder* textureHolder) : isPassed(false)
{
	sprite.setPosition(PlatformPositionGenerator::getPlatformPosition());
} 

void Platform::render(sf::RenderWindow* window) const
{
	window->draw(sprite);
}

void Platform::isAbovePlatform()
{
	isPassed = true;
}


