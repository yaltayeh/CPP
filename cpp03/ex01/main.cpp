#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap copy("⌘-C");
	ClapTrap paste("⌘-V");

	copy.attack(paste);
	paste.beRepaired(5);

	copy.attack(paste);
	paste.attack(copy);
	copy.beRepaired(2);

	return 0;
}