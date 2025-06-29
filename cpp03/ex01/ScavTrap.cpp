#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) :
	ClapTrap(name, 100, 50, 20)
{
	gateKeeperMode = false;
	std::cout << "ScavTrap " << name << " has been created!" << std::endl;
}

void ScavTrap::guardGate()
{
	
	gateKeeperMode = true;
	std::cout << "ScavTrap " << getNmae() << " is now in Gate Keeper mode!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << getNmae() << " has been destroyed!" << std::endl;
}
