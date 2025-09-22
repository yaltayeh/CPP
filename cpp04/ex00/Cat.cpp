/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:45:18 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/09/22 09:32:35 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
	std::cout << " Cat wakeup." << std::endl;	
}

Cat::Cat(const Cat &other)
{
	std::cout << "Cat wakeup(copy)." << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat wakeup(copy assignment)." << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << " Cat sleep." << std::endl;	
}

void Cat::makeSound() const
{
	std::cout << "Cat say: Meow." << std::endl;
}
