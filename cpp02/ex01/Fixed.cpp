#include "Fixed.hpp"
#include <ostream>
#include <iostream>

int const Fixed::_fractionalBits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::Fixed(int value)
{
	std::cout << "Float constructor called" << std::endl;
	Fixed::value = value;
}

Fixed::Fixed(float value)
{
	(void)value;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	value = 0;
}

Fixed &Fixed::operator=(const Fixed &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = f.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

float Fixed::toFloat(void) const
{
	return (value);
}

int Fixed::toInt(void) const
{
	return (value);
}

std::basic_ostream<char>& operator<<(std::basic_ostream<char>& os, const Fixed &f)
{
	os << f.toFloat();
	return os;
}