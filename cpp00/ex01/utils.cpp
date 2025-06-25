#include <iostream>
#include "Contact.hpp"

std::string get_field(std::string key)
{
	std::string value = "";

	while (value.empty())
	{
		std::cout << key << ": " << std::flush;
		std::cin >> value;
		if (std::cin.eof())
			return ("");
		std::cin.clear();
        std::cin.ignore(10000, '\n');
	}
	return (value);
}

std::string truncate(std::string text)
{
	std::string copy = std::string(text);
	if (copy.length() > STRING_WIDE)
	{
		copy = copy.substr(0, STRING_WIDE);
		copy[9] = '.';
	}
	return (copy);
}
