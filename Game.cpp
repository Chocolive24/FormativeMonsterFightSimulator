#include "Game.h"
#include "Monster.h"

#include <iostream>

// Ignore the input in a line. 
void Game::IgnoreLigne()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string Game::GetCin()
{
	std::cout << "-> ";
	std::string userCin;
	std::getline(std::cin, userCin);

	return userCin;
}

void Game::WelcomeScreen()
{
	std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "+++ Welcome to Monster Fight Simulator +++" << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
}

std::string Game::DisplayMainMenu()
{
	// Show the user the possible options of the program.
	std::cout << std::endl;
	std::cout << "======================Menu======================" << std::endl;
	std::cout << "[1] to create a Monster						  " << std::endl;
	std::cout << "[2] to make a battle between 2 Monsters         " << std::endl;
	std::cout << "[3] (or any other key) to quite the program.    " << std::endl;
	std::cout << "================================================" << std::endl;

	// Get the option chosen by the user.
	std::string userAnswer = GetCin();
	system("cls");

	return userAnswer;
}

bool Game::ActivateChosenOption(bool& game, std::string chosenOption)
{
	// If option 1, the user can create a Monster.
	if (chosenOption == "1")
	{
		// TODO: Monster::CreateMonster();

		Monster monster1 = Monster::CreateMonster();
		Monster monster2 = Monster::CreateMonster();
	}

	// If option 2, activate the OptionTwo function which consist to find a phone number with someone's name.
	else if (chosenOption == "2")
	{
		//TODO: battle
	}

	// If option 3, quite the program.
	else
	{
		game = false;
		std::cout << "See you soon !" << std::endl;
	}

	return game;
}
