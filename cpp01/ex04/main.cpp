#include <string>
#include <iostream>
#include <fstream>
#include <exception>


// int main(int argc, char **argv)
// {
// 	std::ifstream ifile;
// 	std::ofstream ofile;

// 	if (argc != 4)
// 	{
// 		std::cerr << "usage: " << argv[0] << " filename s1 s2" << std::endl;
// 		return (1);
// 	}
// 	std::string infilename = argv[1];
// 	std::string outfilename = infilename + ".replace";

// 	ifile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
// 	try
// 	{
// 		ifile.open(infilename);
		
// 		ofile.open(outfilename);
// 	}
// 	catch (const std::ios_base::failure &e)
// 	{
// 		std::cerr << e.what() << '\n';
// 		return (1);
// 	}

// 	return (0);
// }

int main()
{
	std::ofstream ofile;

	ofile.open("test2");
	std::cout << ofile.rdstate() << std::endl;
	return (0);
}