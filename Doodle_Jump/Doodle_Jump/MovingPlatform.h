#ifndef MOVINGPLATFORM_H
#define MOVINGPLATFORM_H

#include "DefaultPlatform.h"

/** @class MovingPlatform
 *  A class containing a specific type of platform.
 */
class MovingPlatform: public DefaultPlatform
{
public:
	/**
	 * \brief Enum class that defines the available directions of moving platform.
	 */
	enum class Direction { Right, Left };

	/**
	 * \brief Constructor of the MovingPlatform class.
	 * \param textureHolder Used to load textures into a sprite.
	 */
	explicit MovingPlatform(TextureHolder* textureHolder);
	
	/**
	 * \brief Destructor of MovingPlatform class
	 */
	~MovingPlatform() = default;

	
	/**
	 * \brief Updates the platform.
	 * \param dt Makes the game frame rate independent
	 */
	void update(const float& dt) override;

protected:
	Direction direction;	///< The current direction in which the platform is moving.
	sf::Vector2f velocity;	///< Velocity of the platform.
};
#endif