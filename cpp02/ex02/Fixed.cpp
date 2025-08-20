/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:48:45 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/08/20 14:46:33 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <ostream>
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed()
{
	value = 0;
}

Fixed::Fixed(const Fixed &f)
{
	this->value = f.value;
}

Fixed::Fixed(int value)
{
	this->value = value << _fractionalBits;
}

Fixed::Fixed(float value)
{
	this->value = roundf(value * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
	value = 0;
}

/* == Operator overloading == */

Fixed &Fixed::operator=(const Fixed &f)
{
	this->value = f.value;
	return *this;
}

bool Fixed::operator>(const Fixed &f) const {
	return (this->value > f.value);
}

bool Fixed::operator<(const Fixed &f) const { 
	return (this->value < f.value);
}

bool Fixed::operator>=(const Fixed &f) const { 
	return (this->value >= f.value);
}

bool Fixed::operator<=(const Fixed &f) const { 
	return (this->value <= f.value);
}

bool Fixed::operator==(const Fixed &f) const { 
	return (this->value == f.value);
}

bool Fixed::operator!=(const Fixed &f) const { 
	return (this->value != f.value);
}

Fixed Fixed::operator+(const Fixed &f) const {
	Fixed ret;

	ret.value = this->value + f.value;
	return ret;
}

Fixed Fixed::operator-(const Fixed &f) const {
	Fixed ret;

	ret.value = this->value - f.value;
	return ret;
}

Fixed Fixed::operator*(const Fixed &f) const {
	Fixed ret;
	
	ret.value = ((long long)this->value * (long long)f.value) >> _fractionalBits;
	return (ret);
}

Fixed Fixed::operator/(const Fixed &f) const {
	Fixed ret;
	
	ret.value = (((long int)this->value << _fractionalBits) / (long int)f.value);
	return (ret);
}

Fixed &Fixed::operator++() {
	++this->value;
	return (*this);
} // Prefix

Fixed &Fixed::operator--() { 
	--this->value;
	return (*this);
} // Prefix

Fixed Fixed::operator++(int) { 
	Fixed ret = *this;
	this->value++;
	return (ret);
} // Postfix

Fixed Fixed::operator--(int) { 
	Fixed ret = *this;
	this->value--;
	return (ret);
} // Postfix

/* == Operator overloading == */


/* == Math functions == */

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b ? a : b);
}

/* == Math functions == */


int Fixed::getRawBits(void) const
{
	return (value);
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
}

float Fixed::toFloat(void) const
{
	return ((value * 1.f) / (1 << _fractionalBits));
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