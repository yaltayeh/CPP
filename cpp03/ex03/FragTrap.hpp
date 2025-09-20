#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
	FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &other);
	~FragTrap();
	void highFivesGuys();
};

#endif	// __FRAGTRAP_HPP__
