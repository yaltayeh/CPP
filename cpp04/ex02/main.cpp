/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:08:04 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/10/03 14:40:18 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

void testNormal()
{
	Animal *animal1 = new Dog();
	Animal *animal2 = new Cat();

	std::cout << "type: " << animal1->getType() << " " << std::endl;
	std::cout << "type: " << animal2->getType() << " " << std::endl;

	// Test ideas
	std::cout << "----- Cat -----" << std::endl;
	animal2->addIdea("I love my owner");
	std::cout << "Cat idea: " << animal2->getIdea(0) << std::endl;
	animal2->makeSound();

	std::cout << "----- Dog -----" << std::endl;
	animal1->addIdea("Chase the ball");
	animal1->makeSound();
	std::cout << "Dog idea: " << animal1->getIdea(0) << std::endl;

	delete animal1;
	delete animal2;
}

void testWrong()
{
	const WrongAnimal *meta = new WrongAnimal();
	WrongAnimal *anim1 = new WrongCat();

	std::cout << "type: " << anim1->getType() << " " << std::endl;

	anim1->makeSound();
	meta->makeSound();

	delete meta;
	delete anim1;
}

int main()
{
	std::cout << "----- Testing Normal Animals -----" << std::endl;
	testNormal();
	std::cout << "----------------------------------" << std::endl;
	std::cout << "----- Testing Wrong Animals -----" << std::endl;
	testWrong();
	std::cout << "----------------------------------" << std::endl;
	return 0;
}