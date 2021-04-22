#include "Game.h"

//MEMORY LEAKS LIBRARIES
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	//MEMORY LEAKS TESTER
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Game game;
	game.run();

	return EXIT_SUCCESS;
}

