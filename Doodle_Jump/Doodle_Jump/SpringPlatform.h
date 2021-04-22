#ifndef SPRINGPLATFORM_H
#define SPRINGPLATFORM_H

#include "DefaultPlatform.h"
#include "Spring.h"


/** @class SpringPlatform
 *  A child class of Default platform. It represents a special type of the platform -namely a platform with a spring.
 */
class SpringPlatform: public DefaultPlatform
{
public:
	/**
	 * \brief Constructor of the SpringPlatform
	 * \param textureHolder Used to load textures into a sprite.
	 */
	explicit SpringPlatform(TextureHolder* textureHolder);

	/**
	 * \brief Function that defines what will happen after collision with a player.
	 * \param player Reference to a player object.
	 */
	void onCollision(Player& player) override;

	/**
	 * \brief The function task is to render a platform to a main window.
	 * \param window Pointer to a main window.
	 */
	void render(sf::RenderWindow* window) const override;

private:
	Spring spring; ///< Spring object that will be placed on the top of a platform.
};

#endif