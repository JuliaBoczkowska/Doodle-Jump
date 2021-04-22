#ifndef DEFAULTPLATFORM_H
#define DEFAULTPLATFORM_H
#include "Platform.h"

/** @class DefaultPlatform
 *  A class containing default behaviour of the platform.
 */
class DefaultPlatform : virtual public Platform
{
public:
	/**
	 * \brief Constructor of the DefaultPlatform class.
	 * \param textureHolder Used to load textures into a sprite.
	 */
	explicit DefaultPlatform(TextureHolder* textureHolder);
	
	/**
	 * \brief Destructor of the DefaultPlatform class
	 */
	~DefaultPlatform() = default;

	/**
	 * \brief This function define actions that will be done after collision with a player.
	 * \param player Thanks to this parameter the platform controls the time in which player will bounce from the platform.
	 */
	void onCollision(Player& player) override;
	
	/**
	 * \brief Updates the platform.
	 * \param dt Makes the game frame rate independent 
	 */
	void update(const float& dt) override;
};

#endif
