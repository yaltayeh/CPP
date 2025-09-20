#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	bool gateKeeperMode;

public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &other);
	~ScavTrap();
	void attack(const std::string &target);
	void guardGate();
	bool isGateKeeperMode() const;
};

#endif	// __SCAVTRAP_HPP__
