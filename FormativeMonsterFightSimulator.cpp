#include "Game.h"
#include "Monster.h"

#include <iostream>

int main()
{
	bool game = true;

	std::map<std::string, Monster> monsters;

	Game::WelcomeScreen();
	Game::ActivateChosenOption(game, Game::DisplayMainMenu(), monsters);

	// ------------------------------------------------------------------------------------------------------------------

	while (game)
	{
		Game::ActivateChosenOption(game, Game::DisplayMainMenu(), monsters);
	}
	
	return EXIT_SUCCESS;
}

