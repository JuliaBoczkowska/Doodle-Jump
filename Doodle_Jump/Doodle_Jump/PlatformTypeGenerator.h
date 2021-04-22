#ifndef PLATFORMTYPEGENERATOR_H
#define PLATFORMTYPEGENERATOR_H
#include <vector>

/** @class PlatformTypeGenerator
 *  A class whose job is to create enums with different platform types.
 *  The platform types are store in enum class.
*/
class PlatformTypeGenerator
{
public:
	/**
     * \brief Default constructor
     */
    PlatformTypeGenerator();
	
	/**
     * \brief Defines different types of platforms
     */
    enum class Type { MOVING, RED, SPRING, DEFAULT_SPRING, BLUE_SPRING, CLOUD, DEFAULT};
	
	/**
     * \brief Generate a platform ID depending on current obtained score and probability.
     * \param currentScore The current score obtained by a player.
     * \return A randomly generated platform type.
     */
    Type getPlatformID(int currentScore);
	
	/**
     * \brief Return a vector with probabilities of occurrence of given platform at a certain height
     * \param currentScore The current score obtained by a player.
     * \return A vector containing obtained probabilities.
     */
    std::vector<int> getProbability(const int& currentScore);

private:
    std::vector<Type> AvailablePlatforms;       ///< Vector with all types of platforms excluding Type::DEFAULT
    Type randomPlatform;                        ///< Randomly generated platform Type
};
#endif


