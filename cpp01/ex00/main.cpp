#include "Zombie.hpp"

int main()
{
	Zombie zombie_stack = Zombie("Stack Zombie");
	Zombie *zombie_heap = newZombie("Heap Zombie");

	zombie_stack.announce();
	zombie_heap->announce();

	delete zombie_heap;
	return (0);
}
