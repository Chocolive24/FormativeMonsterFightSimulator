#include "Game.h"
#include "Monster.h"

#include <iostream>

//TODO emp�cher d'�crire 00... dans les stats
// TODO EMPECHER D?ECRIRE DE LA MERDE PARTOUT NOTAMENT POUR LA RACE ETC
// TODO FAIRE UN JOLI VISUEL POUR AFFICHER LES COMBATS

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

