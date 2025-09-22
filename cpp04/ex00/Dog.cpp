/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:45:18 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/09/21 18:13:08 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << " Dog wakeup." << std::endl;	
	type = "Dog";
}

Dog::Dog(const Dog &other)
{
	std::cout << "Dog wakeup(copy)." << std::endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog wakeup(copy assignment)." << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << " Dog sleep." << std::endl;	
}

void Dog::makeSound() const
{
	std::cout << " Bark." << std::endl;
}
