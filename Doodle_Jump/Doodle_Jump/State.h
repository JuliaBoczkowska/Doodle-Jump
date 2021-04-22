#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>
#include "EssentialData.h"

/** @class State
 *	An abstract class defining the default state interface.  
 */
class State
{
public:
	/**
	 * \brief State constructor
	 * \param gameData data Essential data needed for render and update functions.
	 */
	explicit State(std::shared_ptr<EssentialData> gameData) : data(std::move(gameData))  {}
	
	/**
	 * \brief Virtual destructor of State class.
	 */
	virtual  ~State() = default;
	
	/**
	 * \brief Virtual function that every state needs to define if they inherit from State
	 *		  Process events occurring in the state.(pressed keys, clicked buttons etc.).
	 * \param event Object that holds information of event occurring during the game.
	 */
	virtual void handleInputState(sf::Event &event) = 0;

	/**
	 *	\brief Virtual function that every state needs to define if they inherit from State.
	 *		   Updates logic of the game (moving sprites, collision detection etc.).
	 *	\param dt Makes the game frame rate independent.
	 */
	virtual void updateState(const float& dt) = 0;
	
	/**
	 * \brief Virtual function that every state needs to define if they inherit from State.
	 *		  Render every drawable object to the window.
	 */
	virtual void renderState() = 0;

protected:
	std::shared_ptr<EssentialData> data; ///< Essential data that will be part of each of the states.
};

#endif // !1
