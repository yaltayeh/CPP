/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:08:04 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/09/22 20:57:09 by yaltayeh         ###   ########.fr       */
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
	const Animal *animal1 = new Dog();
	const Animal *animal2 = new Cat();
	
	std::cout << "type: " << animal1->getType() << " " << std::endl;
	std::cout << "type: " << animal2->getType() << " " << std::endl;
	
	animal1->makeSound();
	animal2->makeSound();
	
	delete animal1;
	delete animal2;
}

void TestWrong()
{
	const WrongAnimal *meta = new WrongAnimal();
	const WrongAnimal *animal1 = new WrongCat();
	
	std::cout << "type: " << animal1->getType() << " " << std::endl;
	
	animal1->makeSound();
	meta->makeSound();
	
	delete meta;
	delete animal1;
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