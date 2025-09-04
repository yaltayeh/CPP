#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <string>

#define USE_ENERGY_POINTS(action_name, action)	\
	if (ClapTrap::energyPoints > 0) {							\
		action;									\
		useOneEnergy();							\
	} else {									\
		std::cout << "ClapTrap " << name 		\
				<< " has no energy left to "	\
				<< action_name << "!" 			\
				<< std::endl;					\
	}											\

class ClapTrap
{
private:
	std::string name;
	unsigned int hitPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;

protected:
	ClapTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
	std::string getNmae() const;
	void useOneEnergy();

public:
	ClapTrap(std::string name);
	~ClapTrap();
	void attack(ClapTrap &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif // __CLAPTRAP_HPP__
