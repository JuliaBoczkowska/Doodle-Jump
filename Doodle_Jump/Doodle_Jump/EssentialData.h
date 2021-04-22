#ifndef ESSENTIALDATA_H
#define ESSENTIALDATA_H

#include <SFML/Graphics.hpp>
#include "TextureHolder.h"

class StatesStack; // When included throws a linker error.
class Platform;

struct EssentialData
{
	EssentialData(sf::RenderWindow& window, StatesStack& stack, TextureHolder& holder);

	sf::RenderWindow* window;		///< Window of the game.
	StatesStack* gameStack;			///< Stack of the game
	TextureHolder* textureHolder;	///< Resource holder
};

inline EssentialData::EssentialData
(sf::RenderWindow& window, StatesStack& stack, TextureHolder& holder) :
	window(&window),
	gameStack(&stack),
	textureHolder(&holder) { }


#endif
