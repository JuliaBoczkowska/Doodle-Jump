#pragma once
#include "Button.h"
#include "Score.h"
#include "State.h"
#include "View.h"

/** @class GameOverState
 *  Class representing one of the states found in the game.
 *  It displays a game over screen, that consists of clickable buttons
 *  and the score of the player.
 */
class GameOverState : public State
{
public:
	/**
	 * \brief Constructor of GameOverState.
	 * \param data data Essential data needed for render and update functions.
	 * \param scores Scores obtained by player during game state.
	 */
	GameOverState(std::shared_ptr<EssentialData> data, std::pair<int, int> scores);
	
	/**
	 * \brief Destructor of GameOverState
	 */
	~GameOverState() override = default;
	
	/**
	 * \brief Process events occurring in the state.(pressed keys, return menu etc.).
	 * \param event Object that holds information of event occurring during the game.
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
	void switchState(const std::string& buttonName);

	/**
	 * \brief Initialize a text that will be displayed to the screen.
	 */
	void initText();

private:
	sf::Font font;											///< Font
	sf::Sprite background;									///< Background
	std::pair<int, int> scores;								///< Scores obtained by a player

	View view;												///< Current view
	sf::Text score;											///< Score
	sf::Text highScore;										///< High score
	sf::Text gameOver;										///< Game Over text
	std::vector<std::unique_ptr<Button>> buttons;			///< Vector of buttons
};

