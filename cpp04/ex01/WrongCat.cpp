/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:45:18 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/09/22 09:32:35 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << " WrongCat wakeup." << std::endl;
	brain = new Brain();
}

WrongCat::WrongCat(const WrongCat &other)
{
	std::cout << "WrongCat wakeup(copy)." << std::endl;
	brain = new Brain(*other.brain);
	*this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat wakeup(copy assignment)." << std::endl;
	if (this != &other)
	{
		type = other.type;
		*brain = *other.brain;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << " WrongCat sleep." << std::endl;
	delete brain;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat say: Meow." << std::endl;
}

void WrongCat::addIdea(const std::string &idea)
{
	brain->addIdea(idea);
}

std::string WrongCat::getIdea(int index) const
{
	return (brain->getIdea(index));
}
