#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("Default_ScavTrap", 100, 50, 20)
{
	gateKeeperMode = false;
	std::cout << "ScavTrap {Default_ScavTrap}: Default constructor called!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	gateKeeperMode = false;
	std::cout << "ScavTrap {" << name << "}: Constructor called!" << std::endl;
}

ScavTrap::ScavTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage) : ClapTrap(name, hitPoints, energyPoints, attackDamage)
{
	gateKeeperMode = false;
	std::cout << "ScavTrap {" << name << "}: Parameterized constructor called!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other),
											gateKeeperMode(other.gateKeeperMode)
{
	std::cout << "ScavTrap {" << getName() << "}: Copy constructor called!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		gateKeeperMode = other.gateKeeperMode;
		std::cout << "ScavTrap {" << getName() << "}: Assignment operator called!" << std::endl;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap {" << getName() << "}: Destructor called!" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	EXECUTE_ACTION("Attack",
		std::cout << "ScavTrap {" << getName() << "} attacks {" << target << "}, causing "
				  << getAttackDamage() << " points of damage!" << std::endl;
	);
}

void ScavTrap::guardGate()
{
	EXECUTE_ACTION("Gate Keeper", 
		if (gateKeeperMode)
		{
			std::cout << getName() << " is already in Gate Keeper mode." << std::endl;
			return;
		}
		else
		{
			gateKeeperMode = !gateKeeperMode;
			std::cout << getName() << " Gate Keeper mode: "
					  << (gateKeeperMode ? "enable" : "disable") << std::endl;
		}
	);
}

bool ScavTrap::isGateKeeperMode() const
{
	return gateKeeperMode;
}
