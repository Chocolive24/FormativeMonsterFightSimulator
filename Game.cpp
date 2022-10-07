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
	std::cout << std::endl;

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

void Game::Battle(Monster& monster1, Monster& monster2)
{
	bool isInfinitFight = false;

	int nbrOfTurn = 0;

	if (monster1.GetAttack() <= monster2.GetDefense() && monster2.GetAttack() <= monster1.GetDefense())
	{
		isInfinitFight = true;
	}
	// Check if the monsters attributes are valid to make a battle.
	// If the the attack of the 2 monsters is lower or equal to the defense of the other, neither monster will do damage and win.

	if (monster1.GetRaceToString() != monster2.GetRaceToString() && !isInfinitFight)

		if (monster1.GetSpeed() > monster2.GetSpeed())
		{
			while (true)
			{
				if (monster1.GetHp() > 0 && monster2.GetHp() > 0)
				{
					Monster::Attack(monster1, monster2);
					nbrOfTurn++;

					if (monster1.GetHp() > 0 && monster2.GetHp() > 0)
					{
						Monster::Attack(monster2, monster1);
						nbrOfTurn++;
					}

					else
					{
						break;
					}

				}

			}

		}

		else  
		{
			while (true)
			{
				if (monster1.GetHp() > 0 && monster2.GetHp() > 0)
				{
					Monster::Attack(monster2, monster1);
					nbrOfTurn++;

					if (monster1.GetHp() > 0 && monster2.GetHp() > 0)
					{
						Monster::Attack(monster1, monster2);
						nbrOfTurn++;
					}

					else
					{
						break;
					}
				}
			}
		}

	else if (monster1.GetRaceToString() == monster2.GetRaceToString())
	{
		// The monsters have the same race, so there is no battle
		std::cout << "NOOOOOOOO !!! you cannot make a battle between two Monsters of the same race." << std::endl;
	}

	else
	{
		std::cout << "Neither monster is strong enough to beat the other. So it's a tie !!! " << std::endl;
	}

	if (monster2.GetHp() <= 0)
	{
		std::cout << monster1.GetName() << " is the Winner !!!" << std::endl << std::endl;
		std::cout << "Number of turns = " << nbrOfTurn;
	}

	else if (monster1.GetHp() <= 0)
	{
		std::cout << monster2.GetName() << " is the Winner !!!" << std::endl << std::endl;
		std::cout << "Number of turns = " << nbrOfTurn;
	}
	
}

bool Game::ActivateChosenOption(bool& game, std::string chosenOption, std::map<std::string, Monster>& monsters)
{
	// If option 1, the user can create a Monster.
	if (chosenOption == "1")
	{
		Monster monster = Monster::CreateMonster();

		// Add the Monster created in the Monster collection
		Monster::AddMonster(monsters, monster.GetName(), monster);

		Monster::DisplayMonsters(monsters);
	}

	// If option 2, ask the user 2 Monsters and make a battle bewteen them.
	else if (chosenOption == "2")
	{
		// The Monster collection need at least 2 Monsters to make a battle, so check if it's the case
		if (monsters.size() >= 2)
		{
			std::cout << "Your Monster Collection : " << std::endl;
			Monster::DisplayMonsters(monsters);

			std::cout << "Type the name of the first monster that will fight " << std::endl;
			std::string monster1Name = GetCin();
			std::cout << "Type the name of the second monster that will fight" << std::endl;
			std::string monster2Name = GetCin();

			Monster monster1 = monsters[monster1Name];
			Monster monster2 = monsters[monster2Name];

			Battle(monster1, monster2);
		}

		// The Monster collection doesn't contain enough Monsters to make a battle
		else
		{
			std::cout << "You need at least 2 Monsters to make a battle.  "	<< std::endl;
			std::cout << "You can create Monsters by using the option [1]." << std::endl;
		}
	}

	// If option 3, quite the program.
	else
	{
		game = false;
		std::cout << "See you soon !" << std::endl;
	}

	return game;
}


