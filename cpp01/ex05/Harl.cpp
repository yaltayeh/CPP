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
    std::cout << "debug" << std::endl;
}

void Harl::info(void)
{
}

void Harl::warning(void)
{
}

void Harl::error(void)
{
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
