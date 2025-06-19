#include "contact.hpp"
#include <iostream>
#include <iomanip>

int	contact::read_data(void) {
	contact::first_name = get_field("first name");
	if (contact::first_name == "")
		return (1);
	contact::last_name = get_field("last name");
	if (contact::last_name == "")
		return (1);
	contact::nickname = get_field("nickname");
	if (contact::nickname == "")
		return (1);
	contact::phone_number = get_field("phone number");
	if (contact::phone_number == "")
		return (1);
	contact::darkest_secret = get_field("darkest secret");
	if (contact::darkest_secret == "")
		return (1);
	contact::first_name = truncate(contact::first_name);
	contact::last_name = truncate(contact::last_name);
	contact::nickname = truncate(contact::nickname);
	return (0);
}

int	contact::display(int id) {
	if (contact::first_name == "")
		return (0);
	std::cout	<< std::left
				<< std::setw(STRING_WIDE) << id << "|" 
				<< std::setw(STRING_WIDE) << contact::first_name << "|" 
				<< std::setw(STRING_WIDE) << contact::last_name << "|" 
				<< std::setw(STRING_WIDE) << contact::nickname << std::endl;
	return (1);
}
