#include <iostream>
#include "contact.hpp"

std::string get_field(std::string key)
{
	std::string value = "";

	while (value.empty())
	{
		std::cout << key << ": " << std::flush;
		std::cin >> value;
		if (std::cin.eof())
			return ("");
	}
	return (value);
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
