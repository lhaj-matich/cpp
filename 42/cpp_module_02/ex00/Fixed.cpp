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

//? Why i used a ref here:
//? We use the call by ref here because if we don't we'll be creating a copy of the object and this 
//? function we should be defining how this object is supposed to be copied.
Fixed::Fixed(Fixed const &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixed_value = other.getRawBits();
}

int Fixed::getRawBits() const
{
    std::cout << "Get raw bits called" << std::endl;
}

void    Fixed::setRawBits(int raw)
{
    std::cout << "Set raw bits called" << std::endl;
}

Fixed & Fixed::operator=(const Fixed &rhs)
{
    this->fixed_value = rhs.getRawBits();
    return (*this);
}