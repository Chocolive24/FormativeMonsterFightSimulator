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

void Game::Battle(Monster& monstre1, Monster& monstre2)
{

	int nbrOfTurn = 0;

	if (monstre1.RaceToString() != monstre2.RaceToString())

		if (monstre1.GetSpeed() > monstre2.GetSpeed())
		{
			while (true)
			{
				if (monstre1.GetHp() > 0 && monstre2.GetHp() > 0)
				{
					Monster::Attack(monstre1, monstre2);
					std::cout << monstre1.GetName() << " Hp : " << monstre1.GetHp() << std::endl;
					std::cout << monstre2.GetName() << " Hp : " << monstre2.GetHp() << std::endl;
					nbrOfTurn++;

					if (monstre1.GetHp() > 0 && monstre2.GetHp() > 0)
					{
						Monster::Attack(monstre2, monstre1);
						std::cout << monstre1.GetName() << " Hp : " << monstre1.GetHp() << std::endl;
						std::cout << monstre2.GetName() << " Hp : " << monstre2.GetHp() << std::endl;
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
				if (monstre1.GetHp() > 0 && monstre2.GetHp() > 0)
				{
					Monster::Attack(monstre2, monstre1);
					std::cout << monstre1.GetName() << " Hp : " << monstre1.GetHp() << std::endl;
					std::cout << monstre2.GetName() << " Hp : " << monstre2.GetHp() << std::endl;
					nbrOfTurn++;

					if (monstre1.GetHp() > 0 && monstre2.GetHp() > 0)
					{
						Monster::Attack(monstre1, monstre2);
						std::cout << monstre1.GetName() << " Hp : " << monstre1.GetHp() << std::endl;
						std::cout << monstre2.GetName() << " Hp : " << monstre2.GetHp() << std::endl;
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
		// The monsters have the same race, so there is no battle
		std::cout << "NANANAN do not make a battle between same race" << std::endl;
	}

	if (monstre2.GetHp() <= 0)
	{
		std::cout << monstre1.GetName() << " is the Winner !!!" << std::endl << std::endl;
		std::cout << "Number of turns = " << nbrOfTurn;
	}

	else if (monstre1.GetHp() <= 0)
	{
		std::cout << monstre2.GetName() << " is the Winner !!!" << std::endl << std::endl;
		std::cout << "Number of turns = " << nbrOfTurn;
	}
	
}

bool Game::ActivateChosenOption(bool& game, std::string chosenOption, std::map<std::string, Monster>& monsters)
{
	// If option 1, the user can create a Monster.
	if (chosenOption == "1")
	{
		//std::vector<Monster> monsters;


		Monster monster = Monster::CreateMonster();

		monster.AddMonster(monsters, monster.GetName(), monster);

		monster.DisplayMonsters(monsters);


		//monsters.emplace_back(monster);

		///*Monster monster2 = Monster::CreateMonster();
		//monster.AddMonster(monster2);*/
		////std::string monster1Name = Monster::SetUpName();

		////Monster monster2 = Monster::CreateMonster();
		////std::string monster2Name = Monster::SetUpName();

		////std::pair<std::string, Monster> p1(monster.GetName(), monster);
		////std::pair<std::string, Monster> p2(monster2.GetName(), monster2);

		////monster2.AddMonster(p2);

		//Monster::DisplayMonsters(monsters);
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


