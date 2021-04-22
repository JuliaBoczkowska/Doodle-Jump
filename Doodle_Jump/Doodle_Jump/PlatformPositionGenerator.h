#ifndef PLATFORMPOSITIONGENERATOR_H
#define PLATFORMPOSITIONGENERATOR_H

#include <random>
#include <SFML/System/Vector2.hpp>

/** @class PlatformPositionGenerator
 *  A class that generates unique positions for platforms during their construction.
*/
class PlatformPositionGenerator
{
public:
	/**
	 * \brief Constructor of PlatformPositionGenerator class
	 */
	PlatformPositionGenerator() = default;
	
	/**
	 * \brief Destructor of PlatformPositionGenerator class
	 */
	virtual ~PlatformPositionGenerator() = default;

	/**
	 * \brief Generates platform positions during construction.
	 * \return The position of the platform.
	 */
	static sf::Vector2f getPlatformPosition() ;
	
	/**
	 * \brief It resets position of the platform when there is a change of state. This is needed because of
	 *		  static  variables posY and posX.
	 * \return The starting default positions of the platform.
	 */
	static sf::Vector2f resetPosition();

private:
	static std::mt19937 engine;			///< It produces high quality unsigned integer random numbers. (engine based on Mersenne Twister algorithm)
	static std::random_device dev;		///< A random number generator. It is used to seed engine.

	static float yPos;			///< Starting yPos of Doodle.
	static float xPos;			///< Starting xPos of Doodle.
};

#endif

