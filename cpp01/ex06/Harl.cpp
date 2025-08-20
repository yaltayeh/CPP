#include "Harl.hpp"
#include <iostream>

struct s_complain Harl::complains[] = {
    DEFINE_COMPLAIN("DEBUG", debug),
    DEFINE_COMPLAIN("INFO", info),
    DEFINE_COMPLAIN("WARNING", warning),
    DEFINE_COMPLAIN("ERROR", error),
};

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "\tI allocated a whole zombie horde on the heap just to see if I could.\n"
                "\tNow I've got 42 of them announcing themselves in a loop.\n"
                "\tMy console is a graveyard.\n" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "\tLook, I passed by reference, dereferenced the pointer, and the value still changed.\n"
                "\tI don't know how it works, but I'm taking the win and moving on.\n" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "\tI edited the weapon after giving it to HumanA. \n"
                "\tNow everyone's attacking with a spoon instead of a club.\n"
                "\tI guess shared references cut both ways.\n" << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "\tI used new but forgot delete. Again. Valgrind's screaming,\n"
                "\tand now my memory usage looks like a horror movie. I am the leak.\n" << std::endl;
}

int Harl::get_level_index(std::string level)
{
    for (size_t i = 0; i < sizeof(Harl::complains) / sizeof(*Harl::complains); i++)
        if (Harl::complains[i].level == level)
            return (int)i;
    return -1;
}

void Harl::complain(std::string level)
{
    for (size_t i = 0; i < sizeof(Harl::complains) / sizeof(*Harl::complains); i++)
    {
        if (Harl::complains[i].level == level)
        {
            (this->*Harl::complains[i].func)();
            return;
        }
    }
    std::cout << "not important" << std::endl;
}
