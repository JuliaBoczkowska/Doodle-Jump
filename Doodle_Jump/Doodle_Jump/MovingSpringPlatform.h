#ifndef MOVINGSPRINGPLATFORM_H
#define MOVINGSPRINGPLATFORM_H

#include "MovingPlatform.h"
#include "Spring.h"

/** @class MovingSpringPlatform
 *  A class containing a specific type of platform.
 */
class MovingSpringPlatform : public MovingPlatform
{
public:
	/**
	 * \brief Constructor of MovingSpringPlatform class.
	 * \param textureHolder Used to load textures into a sprite.
	 */
	MovingSpringPlatform(TextureHolder* textureHolder);
	
	/**
	 * \brief This function define actions that will be done after collision with a player.
	 * \param player Thanks to this parameter, the platform controls when the player will jump.
	 */
	void onCollision(Player& player) override;
	
	/**
	 * \brief Renders the platform to the window of the game.
	 * \param window Main window of the game
	 */
	void render(sf::RenderWindow* window) const override;
	
	/**
	 * \brief Function responsible for updating position of the platform.
	 * \param dt Makes the game frame rate independent
	 */
	void update(const float& dt) override;

private:
	Spring spring; ///< Spring object that will be placed on top of the platform.
};

#endif

