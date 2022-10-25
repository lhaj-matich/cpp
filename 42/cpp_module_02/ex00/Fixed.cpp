#include "Fixed.hpp"

Fixed::Fixed() 
{
    this->fixed_value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixed_value = other.getRawBits();
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixed_value);
}

void    Fixed::setRawBits(int raw)
{
    this->fixed_value = raw;
    std::cout << "setRawBits member function called" << std::endl;
}

Fixed & Fixed::operator=(const Fixed &rhs)
{
    std::cout << "Copy assigment operator called" << std::endl;
    this->fixed_value = rhs.getRawBits();
    return (*this);
} 