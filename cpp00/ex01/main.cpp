#include <string>
#include <iostream>
#include "contact.hpp"

int add_handler(contact *contacts, int *i)
{
	if (contacts[*i].read_data())
		return (1);
	*i = (*i + 1) % BOOK_SIZE;
	return (0);
}

void search_handler(contact *contacts, int i)
{
	int nb = 0;
	for (int j = 0; j < BOOK_SIZE; j++)
	{
		if (contacts[i].display(nb))
			nb++;
		i = (i + 1) % BOOK_SIZE;
	}
}

int main()
{
	std::string prompt;
	contact contacts[BOOK_SIZE];
	int i;

	i = 0;
	while (1)
	{
		std::cout << "> " << std::flush;
		std::cin >> prompt;
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