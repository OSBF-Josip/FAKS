#ifndef likovi
#define likovi
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>;
class Enemy
{
protected:
	std::string name;
	int health;
	int damage;
public:
	Enemy() :health(50), damage(5) {};
	Enemy(int h, int d);
	virtual ~Enemy() {};
	virtual int attack() = 0;
	virtual void displayInfo() = 0;
	virtual void reduce_health(int) = 0;
};
class Boss : public Enemy
{
private:
	std::string weapon;
public:
	Boss() :Enemy() {};
	Boss(int h, int d);
	~Boss() {};
	int attack();
	void displayInfo();
	void reduce_health(int);
};
class Monster : public Enemy
{
private:
	std::string ability;
public:
	Monster();
	~Monster() {};
	int attack();
	void displayInfo();
	void reduce_health(int);
};
class Player
{
private:
	std::string name;
	int health;
	std::string weapon;
public:
	Player(std::string c_name = "Rogal Dorn", std::string c_weapon = "Warhammer") :name(c_name), weapon(c_weapon), health(200) { };
	~Player() {};
	int attack();
	void display_info();
};
#endif