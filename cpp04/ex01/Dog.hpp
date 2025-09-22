/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:43:15 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/09/22 09:10:20 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_HPP__
# define __DOG_HPP__

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	std::string type;
	Brain		*brain;

public:
	Dog();
	Dog(const Dog &other);
    Dog &operator=(const Dog &other);
	~Dog();
	void makeSound() const;
};

#endif /* __DOG_HPP__ */
