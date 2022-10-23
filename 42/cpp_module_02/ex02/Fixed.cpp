/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:18:35 by ochoumou          #+#    #+#             */
/*   Updated: 2022/10/22 20:39:40 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// ::Constructors and destructors::

Fixed::Fixed()
{
    this->fixed_value = 0;
}

Fixed::Fixed(int input)
{
    this->fixed_value = input << this->fraction;
}

Fixed::Fixed(float input)
{
    this->fixed_value = roundf(input * (float) (1 << this->fraction));
}

Fixed::~Fixed()
{
}

Fixed::Fixed(Fixed const &other)
{
    this->fixed_value = other.getRawBits();
}

Fixed & Fixed::operator=(Fixed const &rhs)
{
    this->fixed_value = rhs.getRawBits();
    return (*this);
}

// ::Member functions::

int Fixed::getRawBits() const
{
    return (this->fixed_value);
}

int Fixed::toInt() const
{
    return (this->fixed_value >> this->fraction);
}

float Fixed::toFloat() const
{
    return ((float)this->fixed_value / (float)(1 << this->fraction));
}

void    Fixed::setRawBits(int raw)
{
    this->fixed_value = raw;
}

// ::Overloading::

// Overloading the output operator

std::ostream &operator << (std::ostream &output,const Fixed &input)
{
    output << input.toFloat();
    return output;
}

// Overloading the comparasion operator

bool    Fixed::operator> (const Fixed &rhs) const
{
    if (this->fixed_value > rhs.fixed_value)
        return (true);
    return (false);
}

bool    Fixed::operator< (const Fixed &rhs) const
{
    if (this->getRawBits() > rhs.getRawBits())
        return (true);
    return (false);
}

bool    Fixed::operator<= (const Fixed &rhs) const
{
    if (this->getRawBits() <= rhs.getRawBits())
        return (true);
    return (false);
}

bool    Fixed::operator>= (const Fixed &rhs) const
{
    if (this->getRawBits() >= rhs.getRawBits())
        return (true);
    return (false);
}

bool    Fixed::operator== (const Fixed &rhs) const
{
    if (this->getRawBits() == rhs.getRawBits())
        return (true);
    return (false);
}

bool    Fixed::operator!= (const Fixed &rhs) const
{
    if (this->getRawBits() != rhs.getRawBits())
        return (true);
    return (false);
}

// Overloading the arithmetic operators

Fixed Fixed::operator+(const Fixed &rhs)
{
    return Fixed(this->toFloat() + rhs.toFloat());

}

Fixed Fixed::operator-(Fixed const &rhs)
{
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs)
{
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs)
{
    return Fixed(this->toFloat() * rhs.toFloat());
}

// Increament and decrement

Fixed &		Fixed::operator++() {
	this->fixed_value++;
	return *this;
}

Fixed 	Fixed::operator++(int) {
    Fixed fixed(*this);
    this->fixed_value++;
    return fixed;
}

Fixed &		Fixed::operator--() {
	this->fixed_value--;
	return *this;
}

Fixed   Fixed::operator--(int) {
	Fixed fixed(*this);
    this->fixed_value--;
    return fixed;
}

// Max and min functions

Fixed  &Fixed::max(Fixed & value1, Fixed & value2)
{
    if (value1 > value2)
        return (value1);
    return (value2);
}

const Fixed & Fixed::max(const Fixed & value1, const Fixed & value2)
{
    if (value1 > value2)
        return (value1);
    return (value2);
}

Fixed & Fixed::min(Fixed & value1, Fixed & value2)
{
    if (value1 < value2)
        return (value1);
    return (value2);
}

const Fixed & Fixed::min(const Fixed & value1, const Fixed & value2)
{
    if (value1 < value2)
        return (value1);
    return (value2);
}