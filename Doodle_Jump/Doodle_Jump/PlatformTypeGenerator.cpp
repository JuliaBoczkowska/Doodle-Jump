#include "PlatformTypeGenerator.h"
#include <iostream>
#include <map>
#include <random>


PlatformTypeGenerator::PlatformTypeGenerator() :
AvailablePlatforms({ Type::DEFAULT, Type::MOVING, Type::RED, Type::DEFAULT_SPRING, Type::BLUE_SPRING, Type::CLOUD }),
randomPlatform(Type::DEFAULT) { }

PlatformTypeGenerator::Type PlatformTypeGenerator::getPlatformID(int currentScore)
{
	std::vector<int> probabilities(std::move(getProbability(currentScore)));
    static std::random_device dev;
    static std::mt19937 engine(dev());

    //Produces random integer on interval [0, n];
    //Probability of producing certain integer is calculated as the weight of the integer divided by the sum of all n weights
    const std::discrete_distribution<int>discreteDistribution( probabilities.begin(), probabilities.end());

    //Check if last generated platform was red platform
    if (randomPlatform == Type::RED)
    {
    	if(currentScore < 4000)
			return randomPlatform = Type::DEFAULT;
    	
        return randomPlatform = Type::CLOUD;
    }

    return randomPlatform = AvailablePlatforms[discreteDistribution(engine)];
}

std::vector<int> PlatformTypeGenerator::getProbability(const int& currentScore)
{
	if(currentScore <= 2000)
      return { 60, 30, 0, 5, 5, 0 };
    // DEFAULT, MOVING, RED, DEFAULT_SPRING, BLUE_SPRING, CLOUD
	
	if(currentScore <= 4000)
      return { 30, 20, 25, 15, 10, 0 };
    // DEFAULT, MOVING, RED, DEFAULT_SPRING, BLUE_SPRING, CLOUD

	if(currentScore <= 6000)
      return { 15, 20, 25, 10, 10, 20 };
	// DEFAULT, MOVING, RED, DEFAULT_SPRING, BLUE_SPRING, CLOUD

    return { 0, 10, 35, 0, 5, 40 };
    // DEFAULT, MOVING, RED, DEFAULT_SPRING, BLUE_SPRING, CLOUD
}
