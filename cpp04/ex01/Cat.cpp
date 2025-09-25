/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:45:18 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/09/25 14:57:44 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
	std::cout << " Cat wakeup." << std::endl;	
	brain = new Brain();
}

Cat::Cat(const Cat &other)
{
	std::cout << "Cat wakeup(copy)." << std::endl;
	*this = other;
	brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat wakeup(copy assignment)." << std::endl;
	if (this != &other)
	{
		type = other.type;
		*brain = *other.brain;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << " Cat sleep." << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "Cat say: Meow." << std::endl;
}

void Cat::addIdea(const std::string &idea)
{
	brain->addIdea(idea);
}

std::string Cat::getIdea(int index) const
{
	return brain->getIdea(index);
}
