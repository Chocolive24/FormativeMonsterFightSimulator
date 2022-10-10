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
	Monster() = default;

	static std::string GetNumberTyped();

	// ------------------------------------------------------------------------------------------------------------------

	static Race SetUpRace();
	static int SetUpHp();
	static int SetUpAttack();
	static int SetUpDefense();
	static int SetUpSpeed();
	static std::string SetUpName();
	bool SetIsAttacking(bool state);

	// ------------------------------------------------------------------------------------------------------------------

	// Methods to get attributes.
	std::string GetRaceToString();
	int	GetHp()			  { return _hp;		 }
	int	GetAttack()		  { return _attack;  }
	int	GetDefense()	  { return _defense; }
	int	GetSpeed()		  { return _speed;	 }
	std::string GetName() { return _name;  }
	bool GetIsAttacking() { return _isAttacking; }

	// ------------------------------------------------------------------------------------------------------------------

	static Monster CreateMonster();
	static void AddMonster(std::map<std::string, Monster>& monsters, std::string name, Monster& monster);
	static void DisplayMonsters(std::map<std::string, Monster>& monsters);

	// ------------------------------------------------------------------------------------------------------------------

	static void Attack(Monster& attacker, Monster& defender);
};

