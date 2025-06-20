#pragma once
#ifndef __HUMAN_A_H__
#define __HUMAN_A_H__

#include "Weapon.hpp"
#include <string>

class HumanA
{
private:
	std::string		name;
	Weapon&			weapon;

public:
	HumanA(std::string name, Weapon &weapon);
	void attack();
};

#endif
