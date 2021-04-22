#ifndef SCORE_H
#define SCORE_H
#include "Platform.h"
#include "Player.h"

#include <SFML/Graphics/Text.hpp>

/** @class Score
 * As the name suggests the class responsible for displaying the current
 * score obtained by the player.
 */
class Score
{
public:
	/**
	 * \brief Constructor of Score class
	 */
	Score();
	/**
	 * \brief Destructor of Score class
	 */
	~Score() = default;

	/**
	 * \brief Function that initializes the score bar displayed in the game at the top of the screen
	 */
	void initText();
	
	/**
	 * \brief Initialization of colored strip on which the score is displayed
	 */
	void initRectangle();
	
	/**
	 * \brief Updates the logic of the game.
	 * \param player Player is needed in calculation of the score.
	 * \param platforms Player is needed in calculation of the score.
	 */
	void update(Player& player, const std::vector<std::unique_ptr<Platform>>& platforms);
	
	/**
	 * \brief Renders every object to the window.
	 * \param window Pointer ot the main game window.
	 */
	void render(sf::RenderWindow* window);
	
	/**
	 * \brief Add new points to the score. This function is performed in update function.
	 * \param player Player is needed in calculation of the score.
	 * \param platforms Player is needed in calculation of the score.
	 */
	void AddToScore(Player& player, const std::vector<std::unique_ptr<Platform>>& platforms);
	
	/**
	 * \brief Set position of the score bar.
	 * \param pos The position in which the score bar will be displayed.
	 */
	void setPosition(const sf::Vector2f& pos);
	
	/**
	 * \brief When the game is over the new score obtained by
	 * a player is compared by this function. If its bigger than
	 * current score it is becoming the new highest score.
	 */
	void setHighScore() const;
	
	/**
	 * \brief Return the current score, player has obtained.
	 * \return Current score.
	 */
	const int& getCurrentScore() const;

	/**
	 * \brief Displays the highest score.
	 * \param window Pointer to the main game window.
	 */
	void displayHighestScore(sf::RenderWindow* window);

	
	/**
	 * \brief The pair of int values that represents the current score and the highest score earned.Pair of int values 
	 * \return Pair of numbers.
	 */
	std::pair <int, int> getScores() const;

private:
	static int highestScore; ///< Highest score that is present for the whole time of executing the program
	int currentScore; ///< Current score obtained by player

	sf::Font font; ///< Font
	sf::Text counter; ///< The current score displayed in the right corner of the screen.
	sf::Text highScore; ///< The highest score obtained by player.
	sf::RectangleShape rectangle; ///< The colored score bar
};

#endif


