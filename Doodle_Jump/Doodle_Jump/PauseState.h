#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include "State.h"
#include "Button.h"

/** @class PauseState
 *  Class representing one of the states found in the game.
 */
class PauseState: public State
{
public: 
	/**
	 * \brief Constructor of PauseState
	 * \param data Essential data to perform update and render function
	 */
	explicit PauseState(std::shared_ptr<EssentialData> data);
	
	/**
	 * \brief Destructor of Pause State
	 */
	~PauseState() override = default;

	bool requestChange(sf::Event& event) const;

	/**
	* \brief Process events occurring in the state.(pressed keys, clicked button etc.).
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

private:
	std::unique_ptr <Button> button;		///< Resume button
	sf::Sprite sprite;						///< Sprite
};

#endif 

