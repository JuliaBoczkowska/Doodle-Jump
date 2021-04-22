#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>


/** @class Entity
 *  Entity class that has a lot of useful functions which allow easy transfomaration of sprite position.
 *  Each class inheriting from it gets a sprite and a set of these functions. 
 */
class Entity
{
public:
	/**
	 * \brief Constructor of the class Entity.
	 */
	Entity() = default;
	
	/**
	 * \brief Function that return the current x position of the sprite.
	 * \return X value of the sprite.
	 */
	float getX() const;

	/**
	* \brief Function that return the current y position of the sprite.
	* \return Y value of the sprite.
	*/
	float getY() const;

	/**
	* \brief Function that return the width of the sprite in map coordinates.
	* \return Width the sprite.
	*/
	float getWidth() const;

	/**
	* \brief Function that return the height of the sprite in map coordinates.
	* \return Height the sprite.
	*/
	float getHeight() const;

	/**
	* \brief Function that return the width of the sprite in local sprite coordinates.
	* \return Width the sprite.
	*/
	float getLocalWidth() const;

	/**
	* \brief Function that return the height of the sprite in local sprite coordinates.
	* \return Height the sprite.
	*/
	float getLocalHeight() const;
	
	/**
	 * \brief Function that sets position of the sprite on the given coordinates.
	 * \param pos New position coordinates of the sprite.
	 */
	void setPosition(const sf::Vector2f& pos);

	/**
	 * \brief Function that sets the origin in the center of the sprite.
	 * \param pos New position coordinates of the sprite.
	 */
	void setOriginCenter(sf::Vector2f = { 0,0 });
	
	/**
	 * \brief Function that return the sprite.
	 * \return A reference to the sprite.
	 */
	sf::Sprite& getSprite();

protected:
	sf::Sprite sprite;			///< Sprite
	sf::Vector2f position;		///< Position of the sprite
};

#endif
