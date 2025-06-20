#include "Zombie.hpp"
#include <iostream>

void Zombie::announce(void) {
	std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	Zombie::name = name;
}

Zombie::Zombie(std::string name) {
	Zombie::name = name;
}

Zombie::Zombie() {
	Zombie::name = "";
}

Zombie::~Zombie() {
	std::cout << Zombie::name << " really died" << std::endl;
}
