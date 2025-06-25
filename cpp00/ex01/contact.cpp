#include "Contact.hpp"
#include <iostream>
#include <iomanip>

int Contact::read_data(void)
{
	first_name = get_field("first name");
	if (first_name == "")
		return (1);
	last_name = get_field("last name");
	if (last_name == "")
		return (1);
	nickname = get_field("nickname");
	if (nickname == "")
		return (1);
	phone_number = get_field("phone number");
	if (phone_number == "")
		return (1);
	darkest_secret = get_field("darkest secret");
	if (darkest_secret == "")
		return (1);
	return (0);
}

int Contact::display_row(int id)
{
	if (first_name == "")
		return (0);
	std::cout << std::left
			  << std::setw(STRING_WIDE) << id << "|"
			  << std::setw(STRING_WIDE) << truncate(first_name) << "|"
			  << std::setw(STRING_WIDE) << truncate(last_name) << "|"
			  << std::setw(STRING_WIDE) << truncate(nickname) << std::endl;
	return (1);
}

int Contact::display_full(int id)
{
	if (first_name == "")
		return (0);
	std::cout << "id: " << id 						  << "\n"
			  << "first_name: " << first_name 		  << "\n"
			  << "last_name: " << last_name 		  << "\n"
			  << "nickname: " << nickname 			  << "\n"
			  << "phone_number: " << phone_number 	  << "\n"
			  << "darkest_secret: " << darkest_secret << std::endl;
	return (1);
}
