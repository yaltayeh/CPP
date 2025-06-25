#ifndef __FIXED_H__
#define __FIXED_H__

class Fixed
{
private:
	static int const _fractionalBits;
	int value;

public:
	Fixed();
	Fixed(Fixed &f);
	~Fixed();
	Fixed &operator=(const Fixed &f);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif