#include <iostream>
#include <string>

std::string string_toupper(std::string s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		s[i] = std::toupper(s[i]);
		i++;
	}
	return (s);
}

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; i++)
	{
		std::string	arg = std::string(argv[i]);
		std::cout << (i > 1 ? " " : "") << string_toupper(std::string(argv[i]));
	}
	std::cout << std::endl;
	return (0);
}
