#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include <sstream>


int main(int argc, char **argv)
{
	std::ifstream ifile;
	std::ofstream ofile;
	
	if (argc != 4)
	{
		std::cerr << "usage: " << argv[0] << " filename s1 s2" << std::endl;
		return (1);
	}

	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	std::string infilename = argv[1];
	std::string outfilename = infilename + ".replace";

	ifile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	ofile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		ifile.open(infilename);
		ofile.open(outfilename);

		ifile.seekg(0, std::ios::end);
		std::streampos size = ifile.tellg();
		ifile.seekg(0, std::ios::beg);
		
		std::string content;
		content.resize(size);
		ifile.read(&content[0], size);
		ifile.close();
		
		std::size_t pos = 0;
		std::size_t cur = 0;
		while (1)
		{
			cur = pos;
			pos = content.find(s1, pos);
			if (pos == std::string::npos)
				break;
			ofile << content.substr(cur, pos - cur);
			ofile << s2;
			pos += s1.length();
		}
		if (cur < (size_t)size)
			ofile << &content[cur];
		ofile.flush();
		ofile.close();
	}
	catch (const std::ios_base::failure &e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return (1);
	}

	return (0);
}
