/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:43:15 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/09/22 20:56:04 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

#include <string>

class Animal
{
protected:
	std::string type;
	Animal(const std::string &type);

public:
	Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual ~Animal();
	virtual void makeSound() const;
	const std::string &getType() const;
};

#endif /* __ANIMAL_HPP__ */
