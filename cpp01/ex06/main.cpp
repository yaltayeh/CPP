#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <level>" << std::endl;
        return 1;
    }

    Harl harl;
    std::string level = argv[1];
    switch (harl.get_level_index(level))
    {
    case 0:
        harl.complain("DEBUG");
    case 1:
        harl.complain("INFO");
    case 2:
        harl.complain("WARNING");
    case 3: 
        harl.complain("ERROR");
        break;
    default:
        std::cout << "[ https://www.youtube.com/shorts/GqmUV49gxgU ]" << std::endl;
        break;
    }
}