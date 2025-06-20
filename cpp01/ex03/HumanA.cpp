#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) :
	name(name),
	weapon(weapon)
{
}

void HumanA::attack() {
	std::cout 	<< HumanA::name << " attacks with their " 
				<< HumanA::weapon.getType() << std::endl;
}
