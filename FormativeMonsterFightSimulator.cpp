#include "models/audioManager/AudioManager.h"
#include "models/game/Game.h"
#include "models/monster/Monster.h"

#include <iostream>

int main()
{
	bool game = true;

	std::map<std::string, Monster> monsterCollection;

	// Play the menu theme.
	AudioManager::Play("assets/music/menu_theme.wav", true);

	// ------------------------------------------------------------------------------------------------------------------

	while (game)
	{
		Game::WelcomeScreen();
		Game::ActivateChosenOption(game, Game::DisplayMainMenu(), monsterCollection);
	}

	// ------------------------------------------------------------------------------------------------------------------

	return EXIT_SUCCESS;
}