#include "likovi.hpp"
Enemy::Enemy(int h, int d)
{
	if (h < 0 || d < 0) throw std::invalid_argument("Glup si");
	this->health = h;
	this->damage = d;
}
Boss::Boss(int h, int d):Enemy()
{

	this->health += 50;
	int r_weapon = rand() % 5;
	if (r_weapon == 0)
	{
		this->weapon = "Maul";
		this->damage += 50;
	}
	else if (r_weapon == 1)
	{
		this->weapon = "Halberd";
		this->damage += 35;
	}
	else if (r_weapon == 2)
	{
		this->weapon = "Bardiche";
		this->damage += 20;
	}
	else if (r_weapon == 3)
	{
		this->weapon = "Spear";
		this->damage += 10;
	}
	else if (r_weapon == 4)
	{
		this->weapon = "Zweihander";
		this->damage += 30;
	}
}
int Boss::attack()
{		
	return this->damage;
}
void Boss::displayInfo()
{
	std::cout << "Name: " << this->name << "\t\t" << "Health: " << this->health << "\t\t" << "Weapon: " << this->weapon << std::endl;
}
void Boss::reduce_health(int damage)
{
	this->health - damage;
}
Monster::Monster() :Enemy()
{
	this->health += 20;
	int r_ability = rand() % 3;
	if (r_ability == 0)
	{
		this->ability = "Acid";
		this->damage += 30;
	}
	else if (r_ability == 1)
	{
		this->ability = "Fire";
		this->damage += 50;
	}
	else if (r_ability == 2)
	{
		this->ability = "Ice";
		this->damage += 40;
	}
}
int Monster::attack()
{
	return this->damage;
}
void Monster::displayInfo()
{
	std::cout << "Name: " << this->name << "\t\t" << "Health: " << this->health << "\t\t" << "Ability: " << this->ability << std::endl;
}
void Monster::reduce_health(int damage)
{
	this->health - damage;
}
int Player::attack()
{
	return 40;
}
void Player::display_info()
{
	std::cout << "Name: " << this->name << "\t\t" << "Health: " << this->health << "\t\t" << "Weapon: " << this->weapon << std::endl;
}