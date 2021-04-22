#ifndef GANESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "World.h"

/** @class GameState
 *  Class representing one of the states found in the game.
 *	This is the state in which the entire gameplay takes place
 *	It has features specific to other states. All the game
 *	world building is done in the World class
 */
class GameState: public State
{
public:
	/**
	 * \brief Constructor of GameState class.
	 * \param data Essential data needed for render and update functions.
	 */
	explicit GameState(const std::shared_ptr<EssentialData>& data);
	
	/**
	 * \brief Destructor of GameState class.
	 */
	~GameState() override = default;

	/**
	 * \brief Process events occurring in the state.(pressed keys, return menu etc.).
	 * \param event Object that holds information of event occurring during the game
	 */
	void handleInputState(sf::Event& event) override;

	/**
	 * \brief Updates logic of the game (moving sprites, collision detection etc.).
	 */
	void updateState(const float& dt) override;

	/**
	 * \brief Render every drawable object to the window.
	 */
	void renderState() override;
	
	/**
	 * \brief Function that checks if the Key::Escape is clicked, if so
	 * there is a transition to PauseState
	 * \param event Object that holds information of event occurring during the game
	 */
	void checkPause(sf::Event& event);

private:
	World world; ///< Object of class world that creates all objects needed for gameplay.
};

#endif

