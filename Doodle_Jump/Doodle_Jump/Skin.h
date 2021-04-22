#ifndef SKIN_H
#define SKIN_H
#include <SFML/Graphics/Texture.hpp>
#include "TextureHolder.h"


/**
 * \brief Alias for better readability defining the pair of textures.
 */
using CurrentSkin = std::pair<sf::Texture, sf::Texture>;

/** @class Skin
 * Mostly static class that manages the current skin chosen by a player in customize state. 
 */
class Skin
{
public:
	/**
	 * \brief Constructor of skin class
	 */
	Skin() = default;

	/**
	 * \brief Function returning the pair of skins chosen by a player.
	 * \return Pair of textures chosen by a player.
	 */
	static CurrentSkin& getCurrentSkin();

	/**
	 * \brief Sets a new skin on place of the old ones in doodles variable.
	 * \param newSkin new skin to be set as a current chosen.
	 */
	static void setNewSkin(std::pair<sf::Texture, sf::Texture> newSkin);

	/**
	 * \brief When the game is starting this function sets a default skin in case of player
	 *		  does not want to customize it.
	 * \param textureHolder Pointer to texture holder that holds every texture loaded during game.
	 */
	static void setDefaultSkin(TextureHolder* textureHolder);

private:
	static CurrentSkin doodles;
};

#endif