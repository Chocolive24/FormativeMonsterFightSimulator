#include "Game.h"
#include "Monster.h"

#include <iostream>

// TODO refaire les methodes setup pour bien gérer les touches et renvoyer des int
// TODO Deja 2h30 de code sur le menu / methods de monstre-> add au github dans le futur
// TODO COmbat etc...


int main()
{

	bool game = true;

	Game::WelcomeScreen();
	//Game::ActivateChosenOption(game, Game::DisplayMainMenu());

	/*Monster monster1(Race::GOBLIN, 100.5f, 20.0f, 50.7f, 10.876f);
	Monster monster2(Race::TROLL, 150.5f, 30.0f, 70.9f, 20.345f);

	std::cout << monster1.RaceToString() << " " << monster1._hp << " " << monster1._attack << " " << monster1._defense << " " << monster1._speed << std::endl;
	std::cout << monster2.RaceToString() << " " << monster2._hp << " " << monster2._attack << " " << monster2._defense << " " << monster2._speed << std::endl;;*/

	while (game)
	{
		Game::ActivateChosenOption(game, Game::DisplayMainMenu());
		//std::string test = Monster::CreateMonster().RaceToString();
	}
	
	return EXIT_SUCCESS;
}

