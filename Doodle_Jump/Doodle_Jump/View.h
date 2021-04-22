#ifndef VIEW_H
#define VIEW_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/View.hpp>

/** @class View
 * The purpose of this class among other things is to adjust the view to resized window, following the player
 * for the course of the game, smooth effect of diminishing.
 */
class View
{
public:
	/**
	 * \brief Constructor of the class
	 */
	View();

	/**
	 * \brief Follows the player for the duration of the game. It also defines an effect of falling when the player loses.
	 * \param sprite Const reference to a player's sprite.
	 */
	void followPlayer(const sf::Sprite& sprite);
	
	/**
	 * \brief Function that adjust the portview when the window is being resized.
	 * \param windowSize  Current window size
	 * \return returns the new view with new viewport that will be set in main game loop.
	 */
	sf::View resize(const sf::Vector2u &windowSize);
	
	/**
	 * \brief Function returning current view.
	 * \return Current view.
	 */
	static sf::View& getView();
	
	/**
	 * \brief Return a calculated bottom edge of the view screen.
	 * \return Coordinates of bottom edge of the screen.
	 */
	static sf::Vector2f getBottomEdge();

	/**
	 * \brief Return a calculated top edge of the view screen.
	 * \return Coordinates of top edge of the screen.
	 */
	static sf::Vector2f getTopEdge();

private:
	static sf::View view; ///< One view, one game
	sf::FloatRect viewport; ///< Viewport of View
	bool falling; ///< Bool that checks if the player is falling.
	float posY; ///< Position y of teh character when it is falling.
};

#endif


