/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:45:18 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/09/22 09:59:18 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal()
{
	std::cout << "AAnimal constructor." << std::endl;
}

AAnimal::AAnimal(const std::string &type) : type(type)
{
	std::cout << "AAnimal constructor." << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "AAnimal copy constructor." << std::endl;
	*this = other;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	std::cout << "AAnimal copy assignment operator." << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor." << std::endl;	
}

void AAnimal::makeSound() const
{
	std::cout << "AAnimal sound." << std::endl;
}

const std::string &AAnimal::getType() const
{
	return (type);
}
