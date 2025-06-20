
#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <string>

class Zombie {
	public:
		void announce(void);
		void setName(std::string name);

		Zombie();
		Zombie(std::string name);
		~Zombie();
	private:
		std::string name;	
};

Zombie* zombieHorde(int N, std::string name);

#endif