#ifndef TITLESTATE_H
#define TITLESTATE_H

#include "State.h"
#include "PlatformSpawner.h"


/** @class TitleState
 *  Class representing one of the states found in the game.
 *	The purpose of this state is to show welcoming splash art to user.
 */
class TitleState: public State
{
public:
	/**
	 * \brief Constructor of TitleState
	 * \param data Essential data needed for render and update functions.
	 */
	explicit TitleState(std::shared_ptr<EssentialData> data);
	
	/**
	 * \brief Destructor of TitleState
	 */
	~TitleState() override = default;

	/**
	 * \brief Functions that checks if the resume button was pressed or the Key::Escape was pressed.
	 * \return Value that defines if the state will be changed or not.
	 */
	bool requestChange() const;
	
	/**
	 * \brief Function that initializes a text.
	 */
	void initText();

	/**
	 * \brief Loads all textures required for this state.
	 */
	void loadTextures();

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
	 * \brief Function that generates a background depending on chosen height.
	 */
	void generateBackground();

private:
	PlatformSpawner platformGenerator; ///< Platform generator required for background generation
	std::vector<std::unique_ptr<Platform>> platforms; ///< Vector of platforms required for background
	
	sf::Clock clock;			///< Timer
	sf::Sprite sprite;			///< Sprite
	sf::Font font;				///< Loaded font
	sf::Text text;				///< Text
	sf::Text textSecond;		///< Text
};
#endif

