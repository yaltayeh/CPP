#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) : name(name),
									   hitPoints(10),
									   energyPoints(10),
									   attackDamage(0)
{
	std::cout << "ClapTrap " << name << " has been created!" << std::endl;
	std::cout << "Hit Points: " << hitPoints << ", Energy Points: " << energyPoints << ", Attack Damage: " << attackDamage << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " has been destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " has no energy left to attack!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= amount)
	{
		hitPoints = 0;
		energyPoints = 0;
		attackDamage = 0;
		std::cout << "ClapTrap " << name << " has been Dead!" << std::endl;
	}
	else
	{
		hitPoints -= amount;
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! Remaining hit points: " << hitPoints << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	USE_ENERGY_POINTS("repair",
		if (hitPoints == 0)
		{
			std::cout << "ClapTrap " << name << " cannot be repaired because it is dead!" << std::endl;
			return;
		}
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " repairs itself for " << amount << " hit points! Current hit points: " << hitPoints << std::endl;
	);
}
