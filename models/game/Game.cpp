#include "../audioManager/AudioManager.h"
#include "Game.h"
#include "../monster/Monster.h"
#include "../utility/Utility.h"

#include <chrono>
#include <iostream>
#include <map>


namespace Game
{
	// ------------------------------------------------------------------------------------------------------------------

	void WelcomeScreen()
	{
		std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		std::cout << "+++ Welcome to Monster Fight Simulator +++" << std::endl;
		std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	}

	// ------------------------------------------------------------------------------------------------------------------

	std::string DisplayMainMenu()
	{
		// Show the user the possible options of the program.
		std::cout << std::endl;
		std::cout << "======================Menu======================" << std::endl;
		std::cout << "[1] to create a Monster						  " << std::endl;
		std::cout << "[2] to make a battle between 2 Monsters         " << std::endl;
		std::cout << "[3] (or any other key) to quite the program.    " << std::endl;
		std::cout << "================================================" << std::endl;

		// Get the option chosen by the user.
		std::string userAnswer = Utility::GetCin();
		system("cls");

		return userAnswer;
	}

	// ------------------------------------------------------------------------------------------------------------------

	int MonsterMenu()
	{
		std::cout << "What would you like to do ?" << std::endl;
		std::cout << "=================================" << std::endl;
		std::cout << "[1] Continue to create Monsters" << std::endl;
		std::cout << "[2] Back to the menu" << std::endl;
		std::cout << "=================================" << std::endl;

		int userAnswer = std::stoi(Utility::GetNumberTyped());
		system("cls");

		return userAnswer;
	}

	// ------------------------------------------------------------------------------------------------------------------

	int BattleMenu()
	{
		std::cout << std::endl;
		std::cout << "What would you like to do ?	" << std::endl;
		std::cout << "==============================" << std::endl;
		std::cout << "[1] Continue to make Battles  " << std::endl;
		std::cout << "[2] Back to the menu		    " << std::endl;
		std::cout << "==============================" << std::endl;

		int userAnswer = std::stoi(Utility::GetNumberTyped());
		system("cls");
		return userAnswer;
	}

	// ------------------------------------------------------------------------------------------------------------------

	void EnterArenaAnimation()
	{
		AudioManager::Stop();
		AudioManager::Play("assets/music/battle_theme", true);

		std::cout << "Monsters enter the arena";
		for (int waitingLoopIdx = 0; waitingLoopIdx < 16; waitingLoopIdx++)
		{
			std::cout << " . ";
			std::this_thread::sleep_for(std::chrono::milliseconds(400));
			if (waitingLoopIdx % 3 == 0)
			{
				system("cls");
				std::cout << "Monsters enter the arena";
			}
		}

		system("cls");
	}

	// ------------------------------------------------------------------------------------------------------------------

	void Battle(Monster& monster1, Monster& monster2)
	{
		bool isInfiniteFight = false;

		int nbrOfTurn = 0;

		// Check if the monsters attributes are valid to make a battle.
		// If the attack of the 2 monsters is lower or equal to the defense of the other,
		// neither monster will do damage. So the fight would be infinite
		if (monster1.GetAttack() <= monster2.GetDefense() && monster2.GetAttack() <= monster1.GetDefense())
		{
			isInfiniteFight = true;
		}

		if (monster1.GetRaceToString() != monster2.GetRaceToString() && !isInfiniteFight)
		{
			EnterArenaAnimation();

			if (monster1.GetSpeed() > monster2.GetSpeed())
			{
				monster1.SetIsAttacking(true);
				monster2.SetIsAttacking(false);
			}

			else
			{
				monster1.SetIsAttacking(false);
				monster2.SetIsAttacking(true);
			}

			// ----------------------------------------------------------------------------------------------------------

			while (true)
			{
				if (!monster1.IsDead() && !monster2.IsDead())
				{
					nbrOfTurn++;

					Monster& attacker = monster1.GetIsAttacking() ? monster1 : monster2;
					Monster& defender = monster1.GetIsAttacking() ? monster2 : monster1;

					std::cout << "Turn number " << nbrOfTurn << ": "
						<< attacker.GetName() << "'s attack turn.	" << std::endl;

					Monster::Attack(attacker, defender);

					monster1.SetIsAttacking(!monster1.GetIsAttacking());
					monster2.SetIsAttacking(!monster2.GetIsAttacking());

					if (nbrOfTurn % 5 == 0)
					{
						system("cls");
					}

				}

				else
				{
					break;
				}
			}

			std::cout << std::endl << (monster1.IsDead() ? monster2.GetName() : monster1.GetName())
				<< " is the Winner !!!" << std::endl << std::endl;

			std::cout << "Number of turns = " << nbrOfTurn << std::endl;

			// ----------------------------------------------------------------------------------------------------------
		}

		else if (monster1.GetRaceToString() == monster2.GetRaceToString())
		{
			// The monsters have the same race, so there is no battle
			std::cout << "NOOOOOOOO !!! You cannot make a battle between two Monsters of the same race." << std::endl;
		}

		else
		{
			std::cout << "Neither monster is strong enough to beat the other. So there is no fight. " << std::endl;
		}
	}

	// ------------------------------------------------------------------------------------------------------------------

	bool ActivateChosenOption(bool& game, std::string chosenOption, std::map<std::string, Monster>& monsters)
	{
		// If option 1, the user can create a Monster.
		if (chosenOption == "1")
		{

			while (true)
			{
				Monster monster = Monster::CreateMonster();

				// Add the Monster created in the Monster collection
				Monster::AddMonster(monsters, monster.GetName(), monster);

				Monster::DisplayMonsters(monsters);

				int menuChoice = MonsterMenu();

				if (menuChoice != 1)
				{
					break;
				}
			}
		}

		// If option 2, ask the user 2 Monsters and make a battle bewteen them.
		else if (chosenOption == "2")
		{
			// ----------------------------------------------------------------------------------------------------------

			while (true)
			{
				// The Monster collection need at least 2 Monsters to make a battle, so check if it's the case
				if (monsters.size() >= 2)
				{
					Monster::DisplayMonsters(monsters);

					std::cout << "Type the name of the first monster that will fight " << std::endl;
					std::string monster1Name = Utility::GetCin();
					std::cout << "Type the name of the second monster that will fight" << std::endl;
					std::string monster2Name = Utility::GetCin();
					system("cls");

					// Check if the names typed are in the Monster Collection. (contains() need C++20 to work)
					if (monsters.contains(monster1Name) && monsters.contains(monster2Name))
					{
						Monster monster1 = monsters[monster1Name];
						Monster monster2 = monsters[monster2Name];

						Battle(monster1, monster2);

						int menuChoice = BattleMenu();

						if (menuChoice == 1)
						{
							AudioManager::Stop();
							AudioManager::Play("assets/music/menu_theme.wav", true);
						}

						else
						{
							AudioManager::Stop();
							AudioManager::Play("assets/music/menu_theme.wav", true);
							break;
						}
					}

					else
					{
						std::cout << "There is at least one wrong name in your input, please try again." << std::endl << std::endl;
					}
				}

				// The Monster collection doesn't contain enough Monsters to make a battle
				else
				{
					std::cout << "You need at least 2 Monsters to make a battle.  " << std::endl;
					std::cout << "You can create Monsters by using the option [1]." << std::endl << std::endl;
					break;
				}
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
}