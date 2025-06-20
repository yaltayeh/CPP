
#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <string>

class Zombie {
	public:
		void announce(void);
		Zombie(std::string name);
		~Zombie();
	private:
		std::string name;	
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif