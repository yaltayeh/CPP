/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:45:18 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/09/22 09:31:19 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("")
{
	std::cout << "WrongAnimal constructor." << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : type(type)
{
	std::cout << "WrongAnimal constructor." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "WrongAnimal copy constructor." << std::endl;
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal copy assignment operator." << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor." << std::endl;	
}

void WrongAnimal::makeSound() const
{
	std::cout << "Wrong Sound" << std::endl;
}

const std::string &WrongAnimal::getType() const
{
	return (type);
}
