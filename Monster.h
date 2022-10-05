#pragma once
#include <string>

enum class Race
{
	ORC,
	TROLL,
	GOBLIN,
	DEFAULT,
};

class Monster
{
private:

	

public:
	Monster(Race race, float hp, float attack, float defense, float speed);

	Race _race;
	float _hp;
	float _attack;
	float _defense;
	float _speed;

	static Race SetUpRace();
	static float SetUpHp();
	static float SetUpAttack();
	static float SetUpDefense();
	static float SetUpSpeed();

	static Monster CreateMonster();

	std::string RaceToString();
	//static Monster CreateMonster(Monster monster);
};

