#pragma once
#include <map>
#include <string>
#include <vector>

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

	Race _race;
	int _hp;
	int _attack;
	int _defense;
	int _speed;

	std::string _name;

	//std::map<std::string, Monster> _monsters;
	

public:
	Monster(Race race, int hp, int attack, int defense, int speed, std::string& name);

	static std::string GetNumberTyped();

	static Race SetUpRace();
	static int SetUpHp();
	static int SetUpAttack();
	static int SetUpDefense();
	static int SetUpSpeed();
	static std::string SetUpName();

	std::string GetName() { return _name; }
	int GetHp() { return _hp; }
	int GetSpeed() { return _speed; }

	static Monster CreateMonster();

	void AddMonster(std::map<std::string, Monster>& monsters, std::string name, Monster& monster);
	void DisplayMonsters(std::map<std::string, Monster>& monsters);

	static void Attack(Monster& attacker, Monster& defender);

	std::string RaceToString();

};

