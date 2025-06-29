#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage) :
	name(name),
	hitPoints(hitPoints),
	energyPoints(energyPoints),
	attackDamage(attackDamage)
{
}

std::string ClapTrap::getNmae() const
{
	return name;
}

void ClapTrap::useOneEnergy()
{
	if (hasEnergy())
		energyPoints--;
	else
		std::cout << "ClapTrap " << name << " has no energy left!" << std::endl;
}

bool ClapTrap::hasEnergy() const
{
	return energyPoints > 0;
}

ClapTrap::ClapTrap(std::string name) : 
	name(name),
	hitPoints(100),
	energyPoints(50),
	attackDamage(20)
{
	std::cout << "ClapTrap " << name << " has been created!" << std::endl;
	std::cout << "Hit Points: " << hitPoints << ", Energy Points: " << energyPoints << ", Attack Damage: " << attackDamage << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " has been destroyed!" << std::endl;
}

void ClapTrap::attack(ClapTrap &target)
{
	USE_ENERGY_POINTS("attack", {
		std::cout << "ClapTrap " << name << " attacks " << target.name << ", causing " << attackDamage << " points of damage!" << std::endl;
		target.takeDamage(attackDamage);
	});
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= amount)
	{
		hitPoints = 0;
		energyPoints = 0;
		attackDamage = 0;
	}
	else
		hitPoints -= amount;
	
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! Remaining hit points: " << hitPoints << std::endl;
	if (hitPoints == 0)
		std::cout << "ClapTrap " << name << " has been Dead!" << std::endl;
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
