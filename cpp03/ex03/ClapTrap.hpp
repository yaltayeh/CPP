/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 09:21:25 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/09/20 20:37:01 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <string>

#define EXECUTE_ACTION(action_name, action)         \
	{                                               \
		if (getHitPoints() <= 0)                    \
		{                                           \
			std::cout << getName()                  \
					  << " cannot "                 \
					  << action_name << " because " \
					  << "it is dead!"              \
					  << std::endl;                 \
			return;                                 \
		}                                           \
		if (getEnergyPoints() > 0)                  \
		{                                           \
			action;                                 \
			useOneEnergy();                         \
		}                                           \
		else                                        \
		{                                           \
			std::cout << getName()                  \
					  << " has no energy left to "  \
					  << action_name << "!"         \
					  << std::endl;                 \
		}                                           \
	}

class ClapTrap
{
private:
	unsigned int hitPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;

protected:
	std::string name;
	virtual void setName(const std::string &name);
	void setHitPoints(unsigned int hitPoints);
	void setEnergyPoints(unsigned int energyPoints);
	void setAttackDamage(unsigned int attackDamage);

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap();
	virtual void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void useOneEnergy();

	virtual const std::string &getName() const;
	unsigned int getHitPoints() const;
	unsigned int getEnergyPoints() const;
	unsigned int getAttackDamage() const;
};

#endif // __CLAPTRAP_HPP__
