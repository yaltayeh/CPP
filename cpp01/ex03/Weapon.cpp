#include "Weapon.hpp"

Weapon::Weapon(std::string type) :
	type(type)
{
	
}

const std::string &Weapon::getType()
{
	return (Weapon::type);
}

void Weapon::setType(std::string type)
{
	Weapon::type = type;
}
