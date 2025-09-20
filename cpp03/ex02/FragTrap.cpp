#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("Default_FragTrap", 100, 100, 30)
{
	std::cout << "FragTrap {Default_FragTrap}: Default constructor called!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap {" << name << "}: Constructor called!" << std::endl;
}

FragTrap::FragTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage) : ClapTrap(name, hitPoints, energyPoints, attackDamage)
{
	std::cout << "FragTrap {" << name << "}: Parameterized constructor called!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap {" << getName() << "}: Copy constructor called!" << std::endl;
}


FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << "FragTrap {" << getName() << "}: Assignment operator called!" << std::endl;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap {" << getName() << "}: Destructor called!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	EXECUTE_ACTION("High Fives",
		std::cout << getName() << " is requesting high fives!" << std::endl;
	);
}
