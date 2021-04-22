#ifndef PLATFORMSPAWNER_H
#define PLATFORMSPAWNER_H
#include <vector>

#include "Platform.h"
#include "PlatformTypeGenerator.h"
#include "functional"

/** @class PlatformSpawner
 *  A class whose job is to create platforms as well as remove them.
 *  In its most important function it takes a reference to a vector which is then filled with platforms. 
*/
class PlatformSpawner
{
public:
	/**
	 * \brief Constructor of PlatformSpawner class
	 * \param holder Pointer to texture holder that holds all textures loaded during game
	 */
	explicit PlatformSpawner(TextureHolder* holder);
	
	/**
	 * \brief Destructor of PlatformSpawner class
	 */
	~PlatformSpawner() = default;
	
	/**
	 * \brief This function takes a reference to a vector of platforms from a class invoking this 
	 *		  function. The purpose of this function is to add randomly generated platform
	 *		  types until the y position of the last generated platform is greater than
	 *		  the float defining the upper edge of the window. When this value is greater
	 *		  it means that the screen has already been filled with. platforms and the function
	 *		  ends at this point.
	 * \param platforms Reference to a vector of platforms .
	 * \param topWindow Y coordinate of top edge of the window .
	 * \param currentScore Score of the player that defines which platform types needs to be generated.
	 * \param resetPosition If the state was changed the position reset is needed because the x and y value are static.
	 */
	void spawnPlatforms(std::vector<std::unique_ptr<Platform>> &platforms, const float& topWindow, int currentScore, bool resetPosition = false);
	
	/**
	 * \brief The purpose of this function is to delete the platform that are out of player's sight of view.
	 * \param platforms Reference to a vector of platforms
	 * \param bottomWindow Y coordinate of bottom edge of the screen.
	 */
	void erasePlatforms(std::vector<std::unique_ptr<Platform>> &platforms, const float& bottomWindow);

	
	/**
	 * \brief It registers all platform types in the map, in order to call them later when they are needed.
	 * \param holder Pointer to texture holder that holds all textures loaded during whole game.
	 */
	void registerPlatforms(TextureHolder* holder);
	
	/**
	 * This is a template platform factory function. It task is to initialize a map with functions creating various types of platforms.
	 * The aim of this is to create an platform object, anywhere and when I need it.
	 * Using lambda expressions I create a callable function that returns the newly created platforms.
	 * I store these functions in a map where the key is ID of the platform
	 */
	template <typename T>
	void initPlatform(PlatformTypeGenerator::Type platformID, TextureHolder* holder);

private:
	PlatformTypeGenerator randomPlatformType;																///< Storage for randomly generated platform
	std::map<PlatformTypeGenerator::Type, std::function<std::unique_ptr<Platform>()>> platformFactory;		///< Platform factory
};


template <typename T>
void PlatformSpawner::initPlatform(PlatformTypeGenerator::Type platformID, TextureHolder* holder)
{
	this->platformFactory[platformID] = [holder]() { return std::unique_ptr<Platform>(new T(holder)); };
}

#endif