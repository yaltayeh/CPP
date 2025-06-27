#include "Contact.hpp"
#include <iostream>
#include <iomanip>

std::string get_field(std::string key, std::string allowed = "");
std::string truncate(std::string text);

void Contact::read_data(void)
{
	try {
		first_name = get_field("first name");
		last_name = get_field("last name");
		nickname = get_field("nickname");
		phone_number = get_field("phone number", "+0123456789 ");
		darkest_secret = get_field("darkest secret");
	} catch (const std::exception& e) {
		throw e;
	}
}

int Contact::displayInRow(int id)
{
	if (first_name == "")
		return (0);
	std::cout << std::right
			  << std::setw(STRING_WIDE) << id << "|"
			  << std::setw(STRING_WIDE) << truncate(first_name) << "|"
			  << std::setw(STRING_WIDE) << truncate(last_name) << "|"
			  << std::setw(STRING_WIDE) << truncate(nickname) << std::endl;
	return (1);
}

int Contact::displayInCard(int id)
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
