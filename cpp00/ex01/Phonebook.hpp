#ifndef __POHONEBOOK_H__
#define __POHONEBOOK_H__

#include <iostream>
#include <string>
#include "Contact.hpp"

#define CONTACTS_COUNT 8

class Phonebook {
    private:
    Contact contacts[CONTACTS_COUNT];
    size_t  next_index;
    size_t  contacts_count;
public:
    Phonebook();
    void    addContact(Contact c);
    void    displayContacts();
    void    displayContactCard(size_t i);
    size_t  getContactsCount();
};

#endif // __POHONEBOOK_H__