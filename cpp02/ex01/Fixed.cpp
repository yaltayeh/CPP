/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:48:24 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/09/20 07:29:27 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <ostream>
#include <iostream>
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = f.value;
}

Fixed::Fixed(int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = value << _fractionalBits;
}

Fixed::Fixed(float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << _fractionalBits));
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
	return ((value * 1.f)/ (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (value >> _fractionalBits);
}

std::basic_ostream<char>& operator<<(std::basic_ostream<char>& os, const Fixed &f)
{
	os << f.toFloat();
	return os;
}