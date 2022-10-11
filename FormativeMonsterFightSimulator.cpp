#include "Game.h"
#include "Monster.h"

#include <iostream>
#include "audio/AudioManager.h"

int main()
{
	bool game = true;

	std::map<std::string, Monster> monsters;

	AudioManager::Play("audio/menu_theme.wav");

	// ------------------------------------------------------------------------------------------------------------------

	while (game)
	{
		Game::WelcomeScreen();
		Game::ActivateChosenOption(game, Game::DisplayMainMenu(), monsters);
	}

	// ------------------------------------------------------------------------------------------------------------------

	return EXIT_SUCCESS;
}

