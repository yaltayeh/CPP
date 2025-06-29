#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>

class Fixed
{
private:
	static const int _fractionalBits;
	int value;

public:
	Fixed();
	Fixed(const Fixed &f);
	Fixed(int value);
	Fixed(float value);
	~Fixed();
	Fixed &operator=(const Fixed &f);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::basic_ostream<char>& operator<<(std::basic_ostream<char>& os, const Fixed &f);

#endif