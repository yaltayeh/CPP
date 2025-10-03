/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:08:04 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/10/03 14:47:04 by yaltayeh         ###   ########.fr       */
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
	const Animal *meta = new Animal();
	Dog *dog1 = new Dog();
	Cat *cat1 = new Cat();

	std::cout << "type: " << dog1->getType() << " " << std::endl;
	std::cout << "type: " << cat1->getType() << " " << std::endl;
	meta->makeSound();

	// Test ideas
	std::cout << "----- Cat Ideas -----" << std::endl;
	cat1->addIdea("I love my owner");
	std::cout << "Cat idea: " << cat1->getIdea(0) << std::endl;
	cat1->makeSound();

	std::cout << "----- Dog Ideas -----" << std::endl;
	dog1->addIdea("Chase the ball");
	dog1->makeSound();
	std::cout << "Dog idea: " << dog1->getIdea(0) << std::endl;

	delete meta;
	delete dog1;
	delete cat1;
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