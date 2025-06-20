#pragma once
#ifndef __HUMAN_B_H__
#define __HUMAN_B_H__

#include "Weapon.hpp"
#include <string>

class HumanB
{
private:
	std::string		name;
	Weapon			*weapon;

public:
	HumanB(std::string name);
	void setWeapon(Weapon &weapon);
	void attack();
};

#endif
