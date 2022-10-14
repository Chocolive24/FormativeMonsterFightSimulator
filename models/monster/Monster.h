#pragma once

#include <map>
#include <string>

enum class Race
{
	ORC,
	TROLL,
	GOBLIN,
};

class Monster
{
private:

	Race _race{};
	int _hp{};
	int _attack{};
	int _defense{};
	int _speed{};
	std::string _name{};

	bool _isAttacking = false;

public:
	
	Monster(Race race, int hp, int attack, int defense, int speed, std::string& name);

	// Default constructor to copy the monsters from the collection to make a battle between them after.
	Monster() = default;

	// ------------------------------------------------------------------------------------------------------------------

	// Methods to set the attributes values with the input of the user.
	static Race SetUpRace();
	static int SetUpHp();
	static int SetUpAttack();
	static int SetUpDefense();
	static int SetUpSpeed();
	static std::string SetUpName();

	// ------------------------------------------------------------------------------------------------------------------

	// Methods to get attributes.
	std::string GetRaceToString();
	int	GetAttack()		  { return _attack;  }
	int	GetDefense()	  { return _defense; }
	int	GetSpeed()		  { return _speed;	 }
	std::string GetName() { return _name;  }
	bool GetIsAttacking() { return _isAttacking; }

	// Check which monster is attacking.
	bool SetIsAttacking(bool state);

	// Check if a monster is dead.
	bool IsDead() { return _hp <= 0; }

	// ------------------------------------------------------------------------------------------------------------------

	// Methods to create monsters and to store them in the collection.
	static Monster CreateMonster();
	static void AddMonster(std::map<std::string, Monster>& monsters, std::string name, Monster& monster);
	static void DisplayMonsters(std::map<std::string, Monster>& monsters);

	// ------------------------------------------------------------------------------------------------------------------

	// Method to attack during the battle.
	static void Attack(Monster& attacker, Monster& defender);
};