#ifndef CLOUD_H
#define CLOUD_H

#include "DefaultPlatform.h"

/** @class CloudPlatform
 *  A class containing a specific type of platform.
 */
class CloudPlatform : public DefaultPlatform
{
public:
	/**
	 * \brief Constructor of CloudPlatform class.
	 * \param textureHolder Used to load textures into a sprite.
	 */
	CloudPlatform(TextureHolder* textureHolder);

	/**
	 * \brief This function define actions that will be done after collision with a player.
	 * \param player Thanks to this parameter, the platform controls the player's jump.
	 */
	void onCollision(Player& player) override;
	
	/**
	 * \brief  Renders the platform to the window which is passed as an argument to function.
	 * \param window A pointer to window that performs the whole game render.
	 */
	void render(sf::RenderWindow* window) const override;

private:
	bool disappear; ///< Bool value that controls the time at which the platform will disappear from the world.
};

#endif

