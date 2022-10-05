#include "conio.h" // For the _getch() function.
#include "Monster.h"
#include "Game.h"

#include <iostream>



Monster::Monster(Race race, float hp, float attack, float defense, float speed)
{
	_race = race;
	_hp = hp;
	_attack = attack;
	_defense = defense;
	_speed = speed;
}

Race Monster::SetUpRace()
{
	Race race{};

	std::cout << "Choose your Monster's Race." << std::endl;
	std::cout << "=======Race=======" << std::endl;
	std::cout << "[1] Orc.          " << std::endl;
	std::cout << "[2] Troll.        " << std::endl;
	std::cout << "[3] Goblin.       " << std::endl;
	std::cout << "==================" << std::endl;
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

float Monster::SetUpHp()
{
	std::cout << "Set the number of Hp of your Monster." << std::endl;
	std::cout << "-> ";
	std::string result;

	do
	{
		char key = _getch();

		if (key >= '0' && key <= '9')
		{
			result += key;
			std::cout << key;
		}
		else
		{
			break;
		}
	} while (true);

	float hp = std::stoi(result);

	/*float hp;
	std::cin >> hp;*/

	return hp;
}

float Monster::SetUpAttack()
{
	std::cout << "Set the number of Attack Damage of your Monster." << std::endl;
	std::cout << "-> ";
	float attack;
	std::cin >> attack;

	return attack;
}

float Monster::SetUpDefense()
{
	std::cout << "Set the number of Defense Points of your Monster." << std::endl;
	std::cout << "-> ";
	float defense;
	std::cin >> defense;

	return defense;
}

float Monster::SetUpSpeed()
{
	std::cout << "Set the Speed of your Monster." << std::endl;
	std::cout << "-> ";
	float speed;
	std::cin >> speed;

	return speed;
}

Monster Monster::CreateMonster()
{
	Race race = SetUpRace();
	float hp = SetUpHp();
	float attack = SetUpAttack();
	float defense = SetUpDefense();
	float speed = SetUpSpeed();
	Game::IgnoreLigne();
	Monster monster(race, hp, attack, defense, speed);

	std::cout << "Race of monster is : " << monster.RaceToString() << " Hp is : " << " " << monster._hp << " " << monster._attack << " " << monster._defense << " " << monster._speed;

	return monster;
}


std::string Monster::RaceToString()
{
	switch (_race)
	{
		case Race::ORC:
			return "Orc ";
		case Race::TROLL:
			return "Troll ";
		case Race::GOBLIN:
			return "Goblin ";
		default:
			return "Unknown";
	}
}

//Monster Monster::CreateMonster(Monster monster)
//{
//	Monster monster(Race::DEFAULT, 0.0f, 0.0f, 0.0f, 0.0f);
//	std::cout << "Choose your Monster's Race." << std::endl;
//	std::cout << "=======Race=======" << std::endl;
//	std::cout << "[1] Orc.          " << std::endl;
//	std::cout << "[2] Troll.        " << std::endl;
//	std::cout << "[3] Goblin.       " << std::endl;
//	std::cout << "==================" << std::endl;
//	std::string userAnswer = Game::GetCin();
//
//	if (userAnswer == "1")
//	{
//		monster.SetUpRace(Race::ORC);
//		std::cout << monster.RaceToString();
//	}
//	else if (userAnswer == "2")
//	{
//		monster.SetUpRace(Race::TROLL);
//		std::cout << monster.RaceToString();
//	}
//	else if (userAnswer == "3")
//	{
//		monster.SetUpRace(Race::GOBLIN);
//		std::cout << monster.RaceToString();
//	}
//
//	return monster;
//}
