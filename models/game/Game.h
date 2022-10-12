#pragma once

#include "../monster/Monster.h"

#include <string>



class Game
{
public:

	static void IgnoreLine();
	static std::string GetCin();
	static std::string GetNumberTyped();

	static void WelcomeScreen();
	static std::string DisplayMainMenu();

	static void EnterArenaAnimation();
	static void Battle(Monster& monster1, Monster& monster2);

	static int MonsterMenu();
	static int BattleMenu();

	static bool ActivateChosenOption(bool& game, std:: string chosenOption, std::map<std::string, Monster>& monsters);

};

