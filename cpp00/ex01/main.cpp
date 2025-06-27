#include <string>
#include <iostream>
#include "Contact.hpp"
#include "Phonebook.hpp"

void add_handler(Phonebook *pb)
{
	try
	{
		Contact c;

		c.read_data();
		pb->addContact(c);
	}
	catch (const std::exception &e)
	{
		throw e;
	}
}

void search_handler(Phonebook *pb)
{
	size_t nb = pb->getContactsCount();
	pb->displayContacts();

	if (nb == 0)
		return ;
print_target:
	try
	{
		int target;
		std::cout << "Enter Contact ID: " << std::flush;
		std::cin >> target;
		if (!std::cin.good() || target < 0 || target >= (int)nb)
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << target << " out of the range" << std::endl;
			goto print_target;
		}
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		pb->displayContactCard(target);
	}
	catch (const std::exception &e)
	{
		throw e;
	}
}

int main()
{
	std::string prompt;
	Phonebook pb;

	std::cin.exceptions(std::ios_base::eofbit);
	while (1)
	{
		try
		{
			std::cout << "> ";
			std::getline(std::cin, prompt);
			if (prompt == "ADD")
				add_handler(&pb);
			else if (prompt == "SEARCH")
				search_handler(&pb);
			else if (prompt == "EXIT")
				break;
			else
				std::cout << "allowed commands: ADD, SEARCH, EXIT" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "\nEOF" << std::endl;
			return (0);
		}
	}
	std::cout << "Bye :)" << std::endl;
	return (0);
}