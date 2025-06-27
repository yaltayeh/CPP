#ifndef __HARL_H__
#define __HARL_H__

#include <string>

#define DEFINE_COMPLAIN(level, func) \
	{level, &Harl::func}

class Harl
{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	static struct s_complain complains[];

public:
	void complain(std::string level);
	int get_level_index(std::string level);
	
};

struct s_complain
{
	std::string level;
	void (Harl::*func)(void);
};


#endif