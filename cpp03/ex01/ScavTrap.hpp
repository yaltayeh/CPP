#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	bool gateKeeperMode;
public:
	ScavTrap(std::string name);
	void guardGate();
	~ScavTrap();
};

#endif	// __CLAPTRAP_HPP__