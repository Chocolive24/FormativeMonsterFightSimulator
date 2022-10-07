#include "Game.h"
#include "Monster.h"

#include <iostream>

// TODO refaire les methodes setup pour bien gérer les touches et renvoyer des int
// TODO Deja 2h30 de code sur le menu / methods de monstre-> add au github dans le futur
// TODO COmbat etc...

// fini TODO emp^cher les fights infini
//TODO faire que les combats s'arrêtent direct après qu'un monstre est mort
//TODO empêcher d'écrire 00... dans les stats

std::map<std::string, Monster> monsters;

int main()
{
	bool game = true;

	Game::WelcomeScreen();
	Game::ActivateChosenOption(game, Game::DisplayMainMenu(), monsters);

	while (game)
	{
		Game::ActivateChosenOption(game, Game::DisplayMainMenu(), monsters);
	}
	
	return EXIT_SUCCESS;
}

