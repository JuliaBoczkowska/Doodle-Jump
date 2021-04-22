#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "Constants.h"
#include "Entity.h"
#include "Spring.h"
#include "TextureHolder.h"


/** @class Player
 * Class that defines Doodle behavior during the game. Among other
 * things it performs function that controls player's movement.
 */
class Player : public Entity
{
//Friends declarations
friend class World;
friend class Spring;

public:
	/**
	 * \brief Enum class that defines the direction in which the player should look.
	 */
	enum class Direction { Right, Left };

	/**
	 * \brief Constructor of the Player class.
	 * \param textureHolder Holds all textures loaded during game.
	 */
	explicit Player(TextureHolder* textureHolder);

	/**
	 * \brief Destructor of Player class.
	 */
	~Player() = default;

	/**
	 * \brief Updates player's logic every iteration.
	 * \param dt Makes tha game frame independent.
	 */
	void update(const float& dt, const float& bottomEdgeWindow);
	
	/**
	 * \brief Renders everything into the Window.
	 * \param window Pointer to main game window
	 */
	void render(sf::RenderWindow* window) const;

	/**
	 * \brief Function that is changing the bool variable to true if the jump is allowed.
	 */
	void allowJump();
	
	/**
	 * \brief Function defining the logic that will enable jump of the character.
	 * \param dt Makes the game frame independent
	 * \param posY The starting point in which the doodle will spawn
	 */
	void jump(const float& dt, const float& posY = GROUND_HEIGHT);
	
/**
	 * \brief Function defining the logic to move player right/left.
	 * \param dt Makes the game frame independent.
	 */
	void movePlayer(const float& dt);
	
	/**
	 * \brief Function that changes the bool variable to true if the player has started jumping up.
	 * It enables the player to fall when mistake has been made.
	 */
	void endFirstMove();

	/**
	 * \brief When player is in first stage of the game this function prevents
	 *		  him from falling from the map
	 * \param posY The starting point in which the doodle will be kept until the first move is done.
	 */
	void notFalling(const float& posY);
	
	/**
	 * \brief Initializes the sprite with origin and texture ... etc.
	 */
	void initSprite();
	
	/**
	 * \brief Function providing current velocity of player. 
	 * \return The current Y velocity of player.
	 */
	float getVelocity() const;
	
	/**
	 * \brief Flips sprite to the left or right depending to which direction
	 *	      doodle is facing
	 */
	void flipSprite();
	
	/**
	 * \brief Flips sprite to the left.
	 * \param player Player's sprite.
	 */
	static void flipSpriteLeft(sf::Sprite& player);
	
	/**
	 * \brief Flips sprite to the right.
	 * \param player Player's sprite.
	 */
	static void flipSpriteRight(sf::Sprite& player);

private:
	bool jumpOnce;				///< Value defining when the time in which the jump should be performed.
	bool firstMove;				///< If the player has not started jumping up yet, this value is true and it prevents doodle from falling from floor lvl.
	float jumpHeight;			///< Jump height that can be changed by platform in any time.
	
	Direction direction;		///< Direction in which doodle is currently facing
	sf::Vector2f velocity;		////< Current velocity of doodle.
	sf::FloatRect rect;			///< Feet collision box
};

#endif
