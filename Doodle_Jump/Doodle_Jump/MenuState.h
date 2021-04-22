#ifndef MENUSTATE_H
#define MENUSTATE_H 

#include "State.h"
#include "Button.h"
#include "DefaultPlatform.h"
#include "Player.h"

/** @class MenuState
 *  Class representing one of the states found in the game.
 *	This is the state in which the menu is build.
 */
class MenuState: public State
{
public:
	/**
	 * \brief Constructor of MenuState
	 * \param data Essential data needed for update and render
	 */
	explicit MenuState(std::shared_ptr<EssentialData> data);
	
	/**
	 * \brief Destructor of MenuState
	 */
	~MenuState() override = default;

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

	/**
	* \brief Switch state to indicated by clicked button state.
	* \param buttonName Identifier of the button.
	*/
	void switchState(const std::string& buttonName) const;
	
	/**
	 * \brief Initialize a text
	 */
	void initText();
	
	/**
	 * \brief Initialize objects
	 */
	void initObjects();

private:
	sf::Sprite background;									///< Background
	sf::Text text;											///< Text
	sf::Font font;											///< Font
	std::vector<std::unique_ptr<Button>> buttons;			///< Vector of buttons
	
	Player player;											///< Player
	DefaultPlatform platform;								///< Default platform
};


#endif
