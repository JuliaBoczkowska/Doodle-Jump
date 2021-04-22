#include "PlatformSpawner.h"
#include <iostream>
#include "CloudPlatform.h"
#include "MovingSpringPlatform.h"
#include "RedPlatform.h"
#include "SpringPlatform.h"

PlatformSpawner::PlatformSpawner(TextureHolder* holder)
{
	registerPlatforms(holder);
}

void PlatformSpawner::spawnPlatforms(std::vector<std::unique_ptr<Platform>> &platforms, const float& topWindow, int currentScore, bool resetPosition)
{
	//Add the first platform and reset the position
	if (platforms.empty())
	{
		platforms.emplace_back(platformFactory[PlatformTypeGenerator::Type::DEFAULT]());
		
		if(resetPosition)
		{
			platforms.back()->setPosition((PlatformPositionGenerator::resetPosition()));
		}
	}
		
	//Basing on the previously added platform, calculate the position for the new one 
	while ((*platforms.back()).getY() > topWindow)
	{
		//Generate platform
		auto generatedPlat = platformFactory.find(randomPlatformType.getPlatformID(currentScore)); // <- iterator to a pair in map

		//Check if the type exist
		if (generatedPlat == platformFactory.end())
			std::cout << "Requested platform ID does not exist" << std::endl;

		//Add the platform to vector
		platforms.emplace_back(generatedPlat->second());
	}
}

void PlatformSpawner::erasePlatforms(std::vector<std::unique_ptr<Platform>> &platforms, const float& bottomWindow)
{
	//Delete platforms which y coordinate is bigger than the bottom edge of the window.
	//In other words delete the platform that are out of player's sight of view.
	const auto it = std::find_if(platforms.begin(), platforms.end(), 
		[&](std::unique_ptr<Platform>& platform)
			{
				return (platform->getY() >= bottomWindow); // <--- lambda returning bool
			});

	if (it != platforms.end())
		platforms.erase(it);
}

void PlatformSpawner::registerPlatforms(TextureHolder* holder)
{
	initPlatform<DefaultPlatform>(PlatformTypeGenerator::Type::DEFAULT, holder);
	initPlatform<MovingPlatform>(PlatformTypeGenerator::Type::MOVING, holder);
	initPlatform<RedPlatform>(PlatformTypeGenerator::Type::RED, holder);
	initPlatform<SpringPlatform>(PlatformTypeGenerator::Type::DEFAULT_SPRING, holder);
	initPlatform<MovingSpringPlatform>(PlatformTypeGenerator::Type::BLUE_SPRING, holder);
	initPlatform<CloudPlatform>(PlatformTypeGenerator::Type::CLOUD, holder);
}
