#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "Entity.h"
#include "PlatformPositionGenerator.h"
#include "TextureHolder.h"

class Player;

/** @class Platform
 *  An abstract class defining the default platform interface. 
 */
class Platform : public Entity
{
/**
 * \brief A class that can access private parts of Platform class. 
 */
friend class Score;
public:	
	/**
	 * \brief Constructor of the Platform class.
	 * \param textureHolder Used to load textures into a sprite.
	 */
	explicit Platform(TextureHolder* textureHolder);
	
	/**
	 * \brief Destructor of the Platform class.
	 */
	virtual ~Platform() = default;

	/**
	 * \brief This function define actions that will be done after collision with a player.
	 * \param player Thanks to this parameter, the platform controls when the player will jump.
	 */
	virtual void onCollision(Player& player) = 0;
	
	/**
	 * \brief Function responsible for updating position of the platform.
	 * \param dt Makes the game frame rate independent
	 */
	virtual void update(const float& dt) = 0;
	
	/**
	 * \brief Renders the platform to the window of the game.
	 * \param window Main window of the game
	 */
	virtual void render(sf::RenderWindow* window) const;
	
	/**
	 * \brief Checks if the player has passed a platform. If yes, the bool value is set to true.
	 */
	virtual void isAbovePlatform();

private:
	bool isPassed; ///< Variable that checks if the player has jumped above a certain platform
	PlatformPositionGenerator positionGenerator;
};


#endif
