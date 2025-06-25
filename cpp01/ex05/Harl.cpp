#include "Harl.hpp"

void Harl::debug(void)
{
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
    void (Harl::*funcs[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string funcNames[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < sizeof(funcs) / sizeof(*funcs); i++)
    {
        if (funcNames[i] == level)
        {
            (this->*funcs[i])();
            return ;
        }
    }
}
