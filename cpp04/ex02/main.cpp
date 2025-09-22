/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:08:04 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/09/22 09:55:35 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>
#include "AAnimal.hpp"

int main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	// This line will cause a compilation error
	// AAnimal *meta = new AAnimal(); 
	
	i->makeSound();
	delete j; // should not create a leak
	delete i;
	return 0;
}