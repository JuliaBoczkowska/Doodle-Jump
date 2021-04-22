#include "PlatformPositionGenerator.h"
#include "Constants.h"
#include <iostream>

float PlatformPositionGenerator::xPos = GROUND_HEIGHT;
float PlatformPositionGenerator::yPos = SCREEN_HEIGHT;

std::random_device PlatformPositionGenerator::dev;
std::mt19937 PlatformPositionGenerator::engine(dev());

sf::Vector2f PlatformPositionGenerator::getPlatformPosition()
{	
	const auto maxY = static_cast<int>(yPos - JUMP_HEIGHT * 0.6f);
    const auto minY = maxY - static_cast<int>(JUMP_HEIGHT) / 3;
	
	const std::uniform_int_distribution<int> generatePosY(minY, maxY);
	const std::uniform_int_distribution<int> generatePosX(0, (static_cast <int>(SCREEN_WIDTH - PLATFORM_WIDTH)));

	xPos = static_cast<float>(generatePosX(engine));
	yPos = static_cast<float>(generatePosY(engine));
	
    return { xPos, yPos };
}

sf::Vector2f  PlatformPositionGenerator::resetPosition()
{
	yPos = SCREEN_HEIGHT - 400;
	return { xPos, yPos };
}

