#include "Game.h"
#include "Monster.h"

#include <iostream>
#include <map>

// ------------------------------------------------------------------------------------------------------------------

// Ignore the input in a line. 
void Game::IgnoreLigne()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// ------------------------------------------------------------------------------------------------------------------

// Get a whole line typed by the user
std::string Game::GetCin()
{
	std::cout << "-> ";
	std::string userCin;
	std::getline(std::cin, userCin);
	std::cout << std::endl;

	return userCin;
}

// ------------------------------------------------------------------------------------------------------------------

void Game::WelcomeScreen()
{
	std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "+++ Welcome to Monster Fight Simulator +++" << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
}

// ------------------------------------------------------------------------------------------------------------------

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

// ------------------------------------------------------------------------------------------------------------------

void Game::Battle(Monster& monster1, Monster& monster2)
{
	bool isInfiniteFight = false;


	int nbrOfTurn = 0;

	/*Monster attacker{};
	Monster defender{};
	Monster tmpMonster{};*/

	// --------------------------------------------------------------------------------------------------------------

	// Check if the monsters attributes are valid to make a battle.
	// If the attack of the 2 monsters is lower or equal to the defense of the other,
	// neither monster will do damage. So the fight would be infinite
	if (monster1.GetAttack() <= monster2.GetDefense() && monster2.GetAttack() <= monster1.GetDefense())
	{
		isInfiniteFight = true;
	}

	// --------------------------------------------------------------------------------------------------------------

	if (monster1.GetRaceToString() != monster2.GetRaceToString() && !isInfiniteFight)
	{
		// ----------------------------------------------------------------------------------------------------------

		if (monster1.GetSpeed() > monster2.GetSpeed())
		{
			monster1.SetIsAttacking(true);
			monster2.SetIsAttacking(false);
			/*attacker = monster1;
			defender = monster2;*/
		}

		else
		{
			monster1.SetIsAttacking(false);
			monster2.SetIsAttacking(true);
			/*attacker = monster2;
			defender = monster1;*/
		}

		// ----------------------------------------------------------------------------------------------------------

		while (true)
		{
			/*if (monster1.GetIsAttacking())
			{
				attacker = monster1;
				defender = monster2;
			}

			else if (monster2.GetIsAttacking())
			{
				attacker = monster2;
				defender = monster1;
			}*/

			if (monster1.GetHp() > 0 && monster2.GetHp() > 0)
			{
				nbrOfTurn++;

				Monster& attacker = monster1.GetIsAttacking() ? monster1 : monster2;
				Monster& defender = monster1.GetIsAttacking() ? monster2 : monster1;

				std::cout << "Turn number " << nbrOfTurn << ": " 
						  << attacker.GetName() << "'s attack turn.	" << std::endl;

				Monster::Attack(attacker, defender);

				if (nbrOfTurn % 5 == 0) 
				{
					system("cls");
				}

				monster1.SetIsAttacking(!monster1.GetIsAttacking());
				monster2.SetIsAttacking(!monster2.GetIsAttacking());

				/*tmpMonster = attacker;
				attacker   = defender;
				defender   = tmpMonster;*/
			}

			else
			{
				break;
			}

			if (monster1.GetHp() <= 0)
			{
				//std::cout << "===============================================" << std::endl << std::endl;
				std::cout << monster2.GetName() << " is the Winner !!!" << std::endl << std::endl;
				std::cout << "Number of turns = " << nbrOfTurn << std::endl;
			}

			else if (monster2.GetHp() <= 0)
			{
				//std::cout << "===============================================" << std::endl << std::endl;
				std::cout << std::endl << monster1.GetName() << " is the Winner !!!" << std::endl << std::endl;
				std::cout << "Number of turns = " << nbrOfTurn << std::endl;
			}

		}

		// ----------------------------------------------------------------------------------------------------------

	}

	else if (monster1.GetRaceToString() == monster2.GetRaceToString())
	{
		// The monsters have the same race, so there is no battle
		std::cout << "NOOOOOOOO !!! You cannot make a battle between two Monsters of the same race." << std::endl;
	}

	else
	{
		std::cout << "Neither monster is strong enough to beat the other. So it's a tie !!! " << std::endl;
	}

}

// ------------------------------------------------------------------------------------------------------------------

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
		// ----------------------------------------------------------------------------------------------------------

		// The Monster collection need at least 2 Monsters to make a battle, so check if it's the case
		if (monsters.size() >= 2)
		{
			Monster::DisplayMonsters(monsters);

			std::cout << "Type the name of the first monster that will fight " << std::endl;
			std::string monster1Name = GetCin();
			std::cout << "Type the name of the second monster that will fight" << std::endl;
			std::string monster2Name = GetCin();
			system("cls");

			// Check if the names typed are in the Monster Collection. (contains() need C++20 to work)
			if (monsters.contains(monster1Name) && monsters.contains(monster2Name))
			{
				Monster monster1 = monsters[monster1Name];
				Monster monster2 = monsters[monster2Name];

				Battle(monster1, monster2);
			}

			else
			{
				std::cout << "There is at least one wrong name in your input, please try again." << std::endl;
			}
			
			
		}

		// ----------------------------------------------------------------------------------------------------------

		// The Monster collection doesn't contain enough Monsters to make a battle
		else
		{
			std::cout << "You need at least 2 Monsters to make a battle.  "	<< std::endl;
			std::cout << "You can create Monsters by using the option [1]." << std::endl;
		}

		// ----------------------------------------------------------------------------------------------------------

	}

	// If option 3, quite the program.
	else
	{
		game = false;
		std::cout << "See you soon !" << std::endl;
	}

	return game;
}