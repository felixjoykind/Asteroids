#include <iostream>
#include "Defenitions.hpp"
#include "Game.h"

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	Game game(SCREEN_WIDTH, SCREEN_HEIGHT, "Asteroids by @felixjoykind");
	game.Run();

	return EXIT_SUCCESS;
}