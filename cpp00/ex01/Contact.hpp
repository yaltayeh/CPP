#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <string>

#define STRING_WIDE 10

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

public:
	void	read_data(void);
	int		displayInRow(int id);
	int		displayInCard(int id);
};

#endif
