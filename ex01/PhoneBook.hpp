#include <string>

struct s_contact
{
	std::string name;
	std::string phone;
	s_contact	*__next;
};

class PhoneBook {
	public:
		s_contact contacts[8];

}