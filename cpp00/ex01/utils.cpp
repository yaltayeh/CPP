#include <iostream>
#include "Contact.hpp"


void	print_error(std::string str, std::string allowed, size_t pos)
{
	size_t	cur = 0;
	std::cout << "input contian non-valied char '";
	while (pos != std::string::npos)
	{
		if (cur < pos)
			std::cout << str.substr(cur, pos - cur);
		cur = str.find_first_of(allowed, pos);
		std::cout << "\033[1;31m" << str.substr(pos, cur - pos) << "\033[0m";
		pos = str.find_first_not_of(allowed, cur);
	}
	if (cur != std::string::npos)
		std::cout << str.substr(cur);
	std::cout << "'" << std::endl;
}

std::string get_field(std::string key, std::string allowed = "")
{
	std::string	value;

	try
	{
read_data:
		std::cout << key << ": " << std::flush;
		std::getline(std::cin, value);
		if (allowed.empty())
			return (value);

		size_t pos = value.find_first_not_of(allowed);
		if (pos != std::string::npos)
		{
			print_error(value, allowed, pos);
			goto read_data;
		}
		return (value);
	}
	catch (const std::exception &e)
	{
		throw e;
	}
}

std::string truncate(std::string text)
{
	if (text.length() > STRING_WIDE)
	{
		text = text.substr(0, STRING_WIDE);
		text[9] = '.';
	}
	return (text);
}
