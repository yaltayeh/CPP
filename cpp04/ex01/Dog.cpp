/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:45:18 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/10/03 14:46:00 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
	std::cout << " Dog wakeup." << std::endl;	
	brain = new Brain();
}

Dog::Dog(const Dog &other)
{
	std::cout << "Dog wakeup(copy)." << std::endl;
	brain = new Brain(*other.brain);
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog wakeup(copy assignment)." << std::endl;
	if (this != &other)
	{
		type = other.type;
		*brain = *other.brain;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << " Dog sleep." << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << "Dog say: Aw Aw." << std::endl;
}

void Dog::addIdea(const std::string &idea)
{
	brain->addIdea(idea);
}

std::string Dog::getIdea(int index) const
{
	return brain->getIdea(index);
}
