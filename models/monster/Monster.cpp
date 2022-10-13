#include "../game/Game.h"
#include "Monster.h"
#include "../utility/Utility.h"

#include <iostream>
#include <thread>

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

Race Monster::SetUpRace()
{
	Race race{};

	std::cout << "Choose your Monster's Race." << std::endl << std::endl;
	std::cout << "=======Race======="		   << std::endl;
	std::cout << "[1] Orc.          "		   << std::endl;
	std::cout << "[2] Troll.        "		   << std::endl;
	std::cout << "[3] Goblin.       "		   << std::endl;
	std::cout << "=================="		   << std::endl;
	

	do
	{
		int userAnswer = std::stoi(Utility::GetNumberTyped());

		if (userAnswer == 1)
		{
			race = Race::ORC;
			break;
		}

		if (userAnswer == 2)
		{
			race = Race::TROLL;
			break;
		}

		if (userAnswer == 3)
		{
			race = Race::GOBLIN;
			break;
		}

		std::cout << std::endl << "Tap a valid race number please." << std::endl;

	} while (true);
	
	return race;
}

// ------------------------------------------------------------------------------------------------------------------

int Monster::SetUpHp()
{
	std::cout << std::endl << std::endl << "Set the number of Hp of your Monster." << std::endl;

	int hp = std::stoi(Utility::GetNumberTyped());

	return hp;
}

// ------------------------------------------------------------------------------------------------------------------

int Monster::SetUpAttack()
{
	std::cout << std::endl << std::endl << "Set the number of Attack Damage of your Monster." << std::endl;

	int attack = std::stoi(Utility::GetNumberTyped());

	return attack;
}

// ------------------------------------------------------------------------------------------------------------------

int Monster::SetUpDefense()
{
	std::cout << std::endl << std::endl << "Set the number of Defense Points of your Monster." << std::endl;

	int defense = std::stoi(Utility::GetNumberTyped());

	return defense;
}

// ------------------------------------------------------------------------------------------------------------------

int Monster::SetUpSpeed()
{
	std::cout << std::endl << std::endl << "Set the Speed of your Monster." << std::endl;

	int speed = std::stoi(Utility::GetNumberTyped());

	return speed;
}

// ------------------------------------------------------------------------------------------------------------------

std::string Monster::SetUpName()
{
	std::cout << std::endl << std::endl << "Finally, set the name of your Monster." << std::endl;
	std::string name = Utility::GetCin();
	std::cout << std::endl;
	system("cls");

	return name;
}

bool Monster::SetIsAttacking(bool state)
{
	return _isAttacking = state;
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
		std::cout << "Name : "     << it->first					   << " /"
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

	std::cout << "Damages inflicted by " << attacker.GetName() << " : "
			  << damage << std::endl << std::endl;

	std::cout << attacker._name << " Hp : " << attacker._hp << std::endl;
	std::cout << defender._name << " Hp : " << defender._hp	<< std::endl;
	std::cout << "===============================================" << std::endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

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

// ------------------------------------------------------------------------------------------------------------------