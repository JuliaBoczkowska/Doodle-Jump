#ifndef WORLD_H
#define WORLD_H

#include "EssentialData.h"
#include "PlatformSpawner.h"
#include "Player.h"
#include "Score.h"
#include "View.h"

/** @class World
 * Class that collects all the objects appearing in the game to place them on screen in order to update them and render.
 * Some members of this class checks the collision between those objects.
 */
class World
{
friend class GameState; ///< Friend declaration
public:
	/**
	 * \brief Constructor of Worlds class
	 * \param data Pointer to essential data struct that holds window, stack and texture holder.
	 */
	explicit World(const std::shared_ptr<EssentialData> &data);
	
	/**
	 * \brief Destructor of World class.
	 */
	~World() = default;

	/**
	 * \brief Updates the game logic of the game for example movement of player or position of platforms.
	 * \param dt Makes the game frame independent. 
	 */
	void update(const float& dt);
	
	/**
	 * \brief Every iteration renders all objects to the window. 
	 */
	void render();

	/**
	 * \brief Detects collisions between objects.
	 */
	void detectCollision();
	
	/**
	 * \brief Erase platforms after they are out of sight.
	 */
	void erasePlatforms();
	
	/**
	 * \brief Endlessly creates platforms within the player's field of view.
	 */
	void spawnPlatforms();
	
	/**
	 * \brief Loads all textures needed for this stage of the game. 
	 */
	void loadTextures();
	
	/**
	 * \brief Defines the action that will be done after the game is over.
	 *		  It also indicates the change to the new state.
	 * \return value indicating if the game is over or not.
	 */
	bool gameOver() const;

private:
	View view;												///< View of the game
	sf::Sprite background;									///< Background sprite
	std::shared_ptr<EssentialData> data;					///< Essential data needed display and update the state
	Player player;											///< Player
	std::vector<std::unique_ptr<Platform>> platforms;		///< vector with platforms currently seen by player.
	Score score;											///< Score
	PlatformSpawner platformGenerator;						///< Platform Generator
};


#endif 

