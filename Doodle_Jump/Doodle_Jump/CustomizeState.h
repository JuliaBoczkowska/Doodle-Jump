#ifndef CUSTOMIZESTATE_H
#define CUSTOMIZESTATE_H

#include "Button.h"
#include "Skin.h"
#include "State.h"

using Buttons = std::unique_ptr<Button>; ///< Alias for an unique_ptr 

/** @class CustomizeState
 *  Class representing one of the states found in the game.
 *  It allows the user to personalize his character, i.e. change his skin.
 */
class CustomizeState: public State
{
	/**
	* \brief Defines a directions of scrolling the skin.
	*/
	enum class Position { Next, Previous };
public:
	/**
	 * \brief Constructor of the CustomizeState class 
	 * \param data Essential data needed for render and update functions.
	 */
	explicit CustomizeState(std::shared_ptr<EssentialData> data);

	/**
	 * \brief Destructor of CustomizeState class
	 */
	~CustomizeState() override = default;

	/**
	 * \brief Process events occurring in the state.(pressed keys, return menu etc.).
	 * \param event Object that holds information of event occurring during the game
	 */
	void handleInputState(sf::Event& event) override;

	/**
	 * Updates logic of the game (moving sprites, collision detection etc.).
	 */
	void updateState(const float& dt) override;

	/**
	 * Render every drawable object to the window.
	 */
	void renderState() override;

	/**
	 * \brief Switch state to indicated by clicked button state.
	 * \param buttonName Identifier of the button.
	 */
	void switchState(const std::string& buttonName);

	/**
	 * \brief Initialize a button.
	 */
	void initButtons();

	/**
	 * \brief Initialize a doodle.
	 */
	void initDoodle();

	/**
	 * \brief Loads all needed textures.
	 * \param textureHolder A reference to texture holder which holds all loaded textures.
	 */
	void loadTextures(TextureHolder& textureHolder);
	
	/**
	 * \brief Function that changes the current displayed sprite when the user click the button.
	 * \param position defines the direction in which the vector will be iterated
	 */
	void changeSprite(const Position& position);

private:
	std::vector<std::pair<sf::Texture, sf::Texture>> doodles;		///< Vector of all available textures of doodles
	std::vector <std::unique_ptr<Button>> buttons;					///< Vector of buttons
	
	sf::Sprite background;											///< Background
	sf::Sprite currentDoodle;										///< current doodle skin
	
	Buttons next;													///< Next button
	Buttons prev;													///< Previous button
	Buttons save;													///< Save button

	unsigned vectorIndex;											///< Current index of doodle vector
};

#endif
