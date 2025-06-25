#include <string>
#include <iostream>
#include "Contact.hpp"

int add_handler(Contact *contacts, int *i)
{
	if (contacts[*i].read_data())
		return (1);
	*i = (*i + 1) % BOOK_SIZE;
	return (0);
}

int search_handler(Contact *contacts, int i)
{
	int nb = 0;
	for (int j = 0; j < BOOK_SIZE; j++)
	{
		if (contacts[i].display_row(nb))
			nb++;
		i = (i + 1) % BOOK_SIZE;
	}
	if (nb == 0)
	{
		std::cout << "Don't have contacts yet" << std::endl;
		return (0);
	}

print_target:
	int target;
	std::cout << "Enter Contact ID: " << std::flush;
	std::cin >> target;
	if (std::cin.eof())
		return (1);
	if (!std::cin.good() || target < 0 || target >= nb)
	{
		std::cin.clear();
        std::cin.ignore(10000, '\n');
		std::cout << target << " out of the range" << std::endl;
		goto print_target;
	}
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	contacts[target].display_full(target);
	return (0);
}

int main()
{
	std::string prompt;
	Contact contacts[BOOK_SIZE];
	int i;

	i = 0;
	while (1)
	{
		std::cout << "> ";
		std::getline(std::cin, prompt);
		if (std::cin.eof())
			break;
		if (prompt == "ADD")
		{
			if (add_handler(contacts, &i))
				break;
		}
		else if (prompt == "SEARCH")
		{
			search_handler(contacts, i);
		}
		else if (prompt == "EXIT")
		{
			std::cout << "this is EXIT" << std::endl;
			break;
		}
	}
}