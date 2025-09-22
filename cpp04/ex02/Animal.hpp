/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:43:15 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/09/22 18:43:50 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

#include <string>

class Animal
{
protected:
	std::string type;
	Animal();
	Animal(const std::string &type);
	Animal(const Animal &other);

public:
	Animal &operator=(const Animal &other);
	virtual ~Animal();
	virtual void makeSound() const;
	const std::string &getType() const;
};

#endif /* __ANIMAL_HPP__ */
