#include <iostream>
#include <string>


char	*string_toupper(char *s)
{
	char	*_s;

	_s = s;
	while (*s)
	{
		*s = std::toupper(*s);
		s++;
	}
	return (_s);
}

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; i++)
		std::cout << (i > 1 ? " " : "") << string_toupper(argv[i]);
	std::cout << std::endl;
	return (0);
}
