#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Constants.h"
#include "Entity.h"
#include "TextureHolder.h"

/** @class Button
 *  A button class creates a button ready to use in other classes.
 */
class Button : public Entity
{
public:
	/**
	 * \brief Constructor of the Button class that set position texture and font size of the button 
	 * \param textureHolder Used to load textures into a sprite.
	 * \param buttonName  This string will be displayed on a button.
	 * \param centerButton A variable that decide if the button will be put in the center of the screen.
	 * \param pos Position of the button, default position is x = 0, y = 0.
	 * \param offset Offset between two or more buttons defined by the user.
	 * \param fontSize An additionally option for font size, user can use default size.
	 */
	Button(TextureHolder* textureHolder, std::string buttonName, bool centerButton, sf::Vector2f pos = {0.f, 0.f},
	       const float& offset = 0.f, const float& fontSize = BUTTON_TEXT_SIZE);
	
	/**
	 * \brief Destructor of the Button class.
	 */
	~Button() = default;

	/**
	 * \brief Function that handles input from the player.
	 *		  Checks if the mouse position is placed on the button.
	 * \param event Event object passeed from the main game loop.
	 * \param window Pointer to main game window.
	 */
	void handleInput(sf::Event& event, sf::RenderWindow* window);
	
	/**
	 * \brief Updates the color and scale of the button sprite.
	 */
	void update();
	
	/**
	 * \brief Renders the button to the window.
	 * \param window Pointer to main game window.
	 */
	void render(sf::RenderWindow* window) const;

	/**
	 * \brief Function that initializes text with a proper font, color, outline etc.
	 * \param fontSize Custom font size provided by the user.
	 */
	void initText(const float& fontSize);
	
	/**
	 * \brief Function that checks if the button was pressed.
	 * \param event Event object passed from main game loop
	 * \return If yes button is pressed (true), otherwise false.
	 */
	bool isButtonPressed(sf::Event& event) const;
	
	/**
	 * \brief Return the name of the button. Used in states class to define the function that will happen for a certain button.
	 * \return The string presenting the name of button.
	 */
	std::string getButtonName() const;
	
	/**
	 * \brief Defines actions that will happen to a string when a button is NOT active (mouse position is not over the button).
	 */
	void unActive();
	
	/**
	 * \brief Defines actions that will happen to a string when a button is active (mouse position is over the button).
	 */
	void active();

	/**
	 * \brief Function that change the scale of the button.
	 */
	void changeScale(const sf::Vector2f& newScale);

private:
	sf::IntRect buttonArea;				///< Rectangle defining the area of the button.
	sf::Font font;						///< Font
	sf::Text text;						///< Text object
	const std::string buttonName;		///< The string defining the name of the button.
	bool isMouseOver;					///< variable that checks if the mouse position is over the button
	sf::Vector2f scale;					///< Scale multiplier for the button
};

#endif
