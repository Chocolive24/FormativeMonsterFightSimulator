#pragma once
#include <string>

#include "Monster.h"

class Game
{
public:

	static void IgnoreLigne();
	static std::string GetCin();

	static void WelcomeScreen();
	static std::string DisplayMainMenu();

	static void Battle(Monster& monstre1, Monster& monstre2);

	static bool ActivateChosenOption(bool& game, std:: string chosenOption, std::map<std::string, Monster>& monsters);
	
};

