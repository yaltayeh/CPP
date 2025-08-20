#include "PhoneBook.hpp"

void PhoneBook::addContact(Contact c)
{
    contacts[next_index] = c;
    next_index = (next_index + 1) % 8;
    contacts_count = ++contacts_count > 8 ? 8 : contacts_count;
}

void PhoneBook::displayContacts()
{
    size_t nb = 0;
    int i = next_index;

	for (int j = 0; j < 8; j++)
	{
		if (contacts[i].displayInRow(nb))
			nb++;
		i = (i + 1) % 8;
	}
    if (nb == 0)
		std::cout << "Don't have contacts yet" << std::endl;
}

void PhoneBook::displayContactCard(size_t i)
{
    if (i < 0 || i >= contacts_count)
        return ;
    contacts[i].displayInCard(i);
}

size_t PhoneBook::getContactsCount()
{
    return (contacts_count);
}

PhoneBook::PhoneBook()
{
    next_index = 0;
    contacts_count = 0;
}
