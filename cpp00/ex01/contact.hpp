#ifndef __CONTACT_CPP__
#define __CONTACT_CPP__

#include <string>

#define BOOK_SIZE 8
#define STRING_WIDE 10

class contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

public:
	int read_data(void);
	int display(int id);
};

std::string get_field(std::string key);
std::string truncate(std::string text);

#endif