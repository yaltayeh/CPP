/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 09:21:28 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/09/20 13:53:39 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) : name(name),
									   hitPoints(10),
									   energyPoints(10),
									   attackDamage(0)
{
	std::cout << "ClapTrap {" << name << "}: Default constructor called!" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage)
	: name(name),
	  hitPoints(hitPoints),
	  energyPoints(energyPoints),
	  attackDamage(attackDamage)
{
	std::cout << "ClapTrap {" << name << "}: Parameterized constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: name(other.name),
	  hitPoints(other.hitPoints),
	  energyPoints(other.energyPoints),
	  attackDamage(other.attackDamage)
{
	std::cout << "ClapTrap {" << name << "}: Copy constructor called!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	std::cout << "ClapTrap {" << name << "}: Copy assignment operator called!" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap {" << name << "}: Destructor called!" << std::endl;
}

const std::string &ClapTrap::getName() const
{
	return name;
}

void ClapTrap::setName(const std::string &name)
{
	this->name = name;
}

unsigned int ClapTrap::getHitPoints() const
{
	return hitPoints;
}

void ClapTrap::setHitPoints(unsigned int hitPoints)
{
	this->hitPoints = hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return energyPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
	this->energyPoints = energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const
{
	return attackDamage;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage)
{
	this->attackDamage = attackDamage;
}

void ClapTrap::useOneEnergy()
{
	if (ClapTrap::energyPoints > 0)
		energyPoints--;
	else
		std::cout << name << " has no energy left!" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	EXECUTE_ACTION("Attack",
		std::cout << "ClapTrap {" << getName() << "} attacks {" << target << "}, causing "
				  << getAttackDamage() << " points of damage!" << std::endl;
	);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= amount)
	{
		hitPoints = 0;
		energyPoints = 0;
		attackDamage = 0;
		std::cout << name << " has been Dead!" << std::endl;
	}
	else
	{
		hitPoints -= amount;
		std::cout << name << " takes " << amount << " points of damage! Remaining hit points: " << hitPoints << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	EXECUTE_ACTION("repair", {
		if (hitPoints == 0)
		{
			std::cout << name << " cannot be repaired because it is dead!" << std::endl;
			return;
		}
		hitPoints += amount;
		std::cout << name << " repairs itself for " << amount << " hit points! Current hit points: " << hitPoints << std::endl;
	});
}
