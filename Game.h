#pragma once
#include <string>

class Game
{
public:

	static void IgnoreLigne();
	static std::string GetCin();

	static void WelcomeScreen();
	static std::string DisplayMainMenu();
	static bool ActivateChosenOption(bool& game, std:: string chosenOption);
	
};

