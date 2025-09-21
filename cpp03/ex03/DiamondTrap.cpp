#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("Default_DiamondTrap", 100, 50, 30), name("Default_DiamondTrap")
{
	std::cout << "DiamondTrap {Default_DiamondTrap}: Default constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name, 100, 50, 30), name(name)
{
	std::cout << "DiamondTrap {" << name << "}: Constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), name(other.name)
{
	std::cout << "DiamondTrap {" << getName() << "}: Copy constructor called!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << "DiamondTrap {" << getName() << "}: Assignment operator called!" << std::endl;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap {" << getName() << "}: Destructor called!" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << getName() << ", ClapTrap name: " << ClapTrap::getName() << std::endl;
}

const std::string &DiamondTrap::getName() const
{
	return DiamondTrap::name;
}

void DiamondTrap::setName(const std::string &name)
{
	ClapTrap::setName(name);
	DiamondTrap::name = name;
}
