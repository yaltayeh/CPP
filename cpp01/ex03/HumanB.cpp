#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
{
	HumanB::name = name;
	HumanB::weapon = NULL;
}

void HumanB::setWeapon(Weapon &weapon)
{
	HumanB::weapon = &weapon;
}

void HumanB::attack() {
	if (!HumanB::weapon) {
		std::cout	<< HumanB::name << " has no weapon" << std::endl;
	} else {
		std::cout 	<< HumanB::name << " attacks with their " 
					<< HumanB::weapon->getType() << std::endl;
	}
}
