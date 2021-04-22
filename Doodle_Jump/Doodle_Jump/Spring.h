#ifndef SPRING_H
#define SPRING_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "Entity.h"
#include "TextureHolder.h"
class Player;

/** @class Spring
 *  A class defining the behaviour of the spring that will be placed on top of certain type of platform.
 */
class Spring: public Entity
{
public:
	/**
	 * \brief Constructor of the Spring class.
	 * \param textureHolder Used to load textures into a sprite.
	 */
	explicit Spring(TextureHolder* textureHolder);

	/**
	 * \brief Destructor of the Spring class.
	 */
	~Spring()  = default;

	
	/**
	 * \brief Function that checks if the spring collides with a player.
	 * \param player Reference to player object used in collision detection.
	 * \return If the collision returns bool is true otherwise false.
	 */
	bool springCollision(Player& player);
	
	/**
	 * \brief Increases player's jump power when collision with spring is detected
	 * \param player Reference to player object
	 */
	void bouncePlayer(Player& player);
	
	/**
	 * \brief Set position of the spring at the top edge of the platform
	 * \param pos Position of the platform.
	 */
	void setSpringPosition(const sf::Vector2f& pos);
	
	/**
	 * \brief Function that renders the spring to the window.
	 * \param window Pointer to main window of the game.
	 */
	void render(sf::RenderWindow* window) const;


private:
	TextureHolder& textureHolder;	///< Used to load many textures into a sprite.
};;
#endif
