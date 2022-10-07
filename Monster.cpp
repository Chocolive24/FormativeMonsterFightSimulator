#include "conio.h" // For the _getch() function.
#include "Game.h"
#include "Monster.h"

#include <algorithm>
#include <iostream>

// ------------------------------------------------------------------------------------------------------------------

Monster::Monster(Race race, int hp, int attack, int defense, int speed, std::string& name)
{
	_race = race;
	_hp = hp;
	_attack = attack;
	_defense = defense;
	_speed = speed;
	_name = name;
}
// ------------------------------------------------------------------------------------------------------------------

std::string Monster::GetNumberTyped()
{
	std::cout << "-> ";

	std::string numberTyped;

	do
	{
		char key = _getch();

		if (key >= '0' && key <= '9')
		{
			numberTyped += key;
			std::cout << key;
		}

		// If the key pressed is "delete".
		if (key == 8)
		{
			// If the attribute's value is not empty.
			if (!numberTyped.empty())
			{
				// Delete the last character and put the cursor back from 1 character in the console.
				numberTyped.pop_back();
				std::cout << "\b \b";
			}
		}

		if (key == 13 && numberTyped != "0")
		{
			if (numberTyped.empty())
			{
				// The attribute's value is empty, so ask again to enter a number of hp
				std::cout << std::endl << "No value entered. Please enter a valid one" << std::endl;
				std::cout << "-> ";
			}

			break;

		}
	} while (true);

	return numberTyped;
}

// ------------------------------------------------------------------------------------------------------------------

Race Monster::SetUpRace()
{
	Race race{};

	std::cout << "Choose your Monster's Race." << std::endl << std::endl;
	std::cout << "=======Race======="		   << std::endl;
	std::cout << "[1] Orc.          "		   << std::endl;
	std::cout << "[2] Troll.        "		   << std::endl;
	std::cout << "[3] Goblin.       "		   << std::endl;
	std::cout << "=================="		   << std::endl;
	std::string userAnswer = Game::GetCin();

	if (userAnswer == "1")
	{
		race = Race::ORC;
	}
	else if (userAnswer == "2")
	{
		race = Race::TROLL;
	}
	else if (userAnswer == "3")
	{
		race = Race::GOBLIN;
	}

	return race;
}

// ------------------------------------------------------------------------------------------------------------------

int Monster::SetUpHp()
{
	std::cout  << "Set the number of Hp of your Monster." << std::endl;

	int hp = std::stoi(GetNumberTyped());

	return hp;
}

// ------------------------------------------------------------------------------------------------------------------

int Monster::SetUpAttack()
{
	std::cout << std::endl << std::endl << "Set the number of Attack Damage of your Monster." << std::endl;

	int attack = std::stoi(GetNumberTyped());

	return attack;
}

// ------------------------------------------------------------------------------------------------------------------

int Monster::SetUpDefense()
{
	std::cout << std::endl << std::endl << "Set the number of Defense Points of your Monster." << std::endl;

	int defense = std::stoi(GetNumberTyped());

	return defense;
}

// ------------------------------------------------------------------------------------------------------------------

int Monster::SetUpSpeed()
{
	std::cout << std::endl << std::endl << "Set the Speed of your Monster." << std::endl;

	int speed = std::stoi(GetNumberTyped());

	return speed;
}

// ------------------------------------------------------------------------------------------------------------------

std::string Monster::SetUpName()
{
	std::cout << std::endl << std::endl << "Finally, set the name of your Monster." << std::endl;
	std::string name = Game::GetCin();
	std::cout << std::endl;
	system("cls");

	return name;
}

// ------------------------------------------------------------------------------------------------------------------

Monster Monster::CreateMonster()
{
	Race race = SetUpRace();
	int hp = SetUpHp();
	int attack = SetUpAttack();
	int defense = SetUpDefense();
	int speed = SetUpSpeed();
	std::string name = SetUpName();

	Monster monster(race, hp, attack, defense, speed, name);

	return monster;
}

// ------------------------------------------------------------------------------------------------------------------

void Monster::AddMonster(std::map<std::string, Monster>& monsters, std::string name, Monster& monster)
{
	std::string monsterName = name;
	Monster monsterObject = monster;
	std::pair<std::string, Monster> p(monsterName, monsterObject);
	monsters.insert(p);
}

// ------------------------------------------------------------------------------------------------------------------

void Monster::DisplayMonsters(std::map<std::string, Monster>& monsters)
{
	std::cout << "Your Monster Collection :" << std::endl << std::endl;

	// Print the Monsters with their attributes (alphabetical order).
	for (auto it = monsters.begin(); it != monsters.end(); it++)
	{
		// First = key, second = value.
		std::cout << "Name : "     << it->first					   << " / "
				  << " Race : "    << it->second.GetRaceToString() << " /"
				  << " Hp : "      << it->second._hp			   << " /"
				  << " Attack : "  << it->second._attack		   << " /"
				  << " Defense : " << it->second._defense		   << " /"
			      << " Speed : "   << it->second._speed			   << " /" << std::endl << std::endl; 
	}
}

// ------------------------------------------------------------------------------------------------------------------

void Monster::Attack(Monster& attacker, Monster& defender)
{
	int damage = attacker._attack - defender._defense;

	if (damage < 0)
	{
		damage = 0;
	}
	defender._hp -= damage;

	if (defender._hp < 0)
	{
		defender._hp = 0;
	}

	std::cout << " Damages inflicted by " << attacker.GetName() << " : "
			  << damage << std::endl << std::endl;

	std::cout << attacker._name << " Hp : " << attacker._hp << std::endl;
	std::cout << defender._name << " Hp : " << defender._hp	<< std::endl;
}

// ------------------------------------------------------------------------------------------------------------------

std::string Monster::GetRaceToString()
{
	switch (_race)
	{
		case Race::ORC:
			return "Orc";
		case Race::TROLL:
			return "Troll";
		case Race::GOBLIN:
			return "Goblin";
		default:
			return "Unknown";
	}
}