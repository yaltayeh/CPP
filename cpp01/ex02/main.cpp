#include <string>
#include <iostream>

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout	<< "brain: " << brain 
				<< "\npointer: " << stringPTR 
				<< "\nreference: " << stringREF 
				<< std::endl;
	return (0);
}
