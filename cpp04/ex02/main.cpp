/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:08:04 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/09/25 15:08:07 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

void TestNormal()
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

void TestWrong()
{
	const WrongAnimal *meta = new WrongAnimal();
	WrongCat *cat = new WrongCat();

	std::cout << "type: " << cat->getType() << " " << std::endl;

	cat->makeSound();
	meta->makeSound();
	
	// Test ideas
	std::cout << "----- Wrong Cat Ideas -----" << std::endl;
	cat->addIdea("I doesn't love my owner");
	std::cout << "Wrong Cat idea: " << cat->getIdea(0) << std::endl;
	cat->makeSound();

	delete meta;
	delete cat;
}

int main()
{
	std::cout << "----- Testing Normal Animals -----" << std::endl;
	TestNormal();
	std::cout << "----------------------------------" << std::endl;
	std::cout << "----- Testing Wrong Animals -----" << std::endl;
	TestWrong();
	std::cout << "----------------------------------" << std::endl;
	return 0;
}