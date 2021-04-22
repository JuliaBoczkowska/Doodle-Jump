#ifndef GAME_H
#define GAME_H

#include "StatesStack.h"
#include "EssentialData.h"
#include "Platform.h"
#include "View.h"

/** @class Game
 * Contains the game loop. Initializes the window and all necessary objects. Calls appropriate functions from other classes to perform run() function.
 */
class Game
{
public:
	
	/**
	 * \brief Constructor of the game class
	 */
	Game();

	
	/**
	 * \brief Destructor of the game class
	 */
	~Game() = default;

	/**
	 * Game loop calls functions depending on the current game state.
	 * For example when game state is equal to "Playing" calls all necessary update and draw functions.
	 */
	void run();

	/**
	 * Process all events occurring in the all states.(pressed keys, exit etc.).
	 */
	void handleInput();

	/**
	 * Updates logic of the game (moving sprites, collision detection etc.). 
	 */
	void update(const float& deltaTime);

	/**
	 * Render every drawable object to the window.
	 */
	void render();

private:			
	const sf::Time deltaTime = sf::seconds(1.f / 60.f);			///< Delta time
	StatesStack stateStack;												///< State stack
	sf::RenderWindow window;											///< Window of the game
	TextureHolder textureHolder;										///< Texture holder
	View view;															///< View object
	std::shared_ptr<EssentialData> essentialData;						///< Essential data that will be send to every state.
};
#endif