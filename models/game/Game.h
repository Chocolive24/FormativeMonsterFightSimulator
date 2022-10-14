#pragma once

#include "../monster/Monster.h"

#include <string>

// Namespace to store function used by the game.
namespace Game
{
	// First page menus.
	void WelcomeScreen();
	std::string DisplayMainMenu();

	// Second page menus.
	int MonsterMenu();
	int BattleMenu();

	// Battle system
	void EnterArenaAnimation();
	void Battle(Monster& monster1, Monster& monster2);

	// Activate the option chosen in the main menu.
	bool ActivateChosenOption(bool& game, std::string chosenOption, std::map<std::string, Monster>& monsters);
}
