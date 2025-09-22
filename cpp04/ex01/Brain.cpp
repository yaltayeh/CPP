/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 08:59:08 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/09/22 09:15:40 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain constructor." << std::endl;
    count = 0;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor." << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain copy assignment operator." << std::endl;
	if (this != &other)
	{
        for (size_t i = 0; i < sizeof(ideas) / sizeof(ideas[0]); i++)
			ideas[i] = other.ideas[i];
		count = other.count;
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor." << std::endl;	
}

void Brain::addIdea(const std::string &idea)
{
    ideas[count % (sizeof(ideas) / sizeof(ideas[0]))] = idea;
    count++;
}

const std::string &Brain::getIdea(size_t i) const
{
    if (i >= (sizeof(ideas) / sizeof(ideas[0])))
        throw std::out_of_range("Index out of range (0, 99)");
    return ideas[i];
}
