#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor is called" << std::endl;
}

Fixed::Fixed(int input)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixed_value = input << this->fraction;
}

Fixed::Fixed(float input)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixed_value = input * (float) (1 << this->fraction);
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

Fixed & Fixed::operator=(const Fixed &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->fixed_value = rhs.getRawBits();
    return (*this);
}

int Fixed::getRawBits() const
{
    return (this->fixed_value);
}

int Fixed::toInt() const
{
    return (this->fixed_value / (1 << this->fraction));
}

float Fixed::toFloat() const
{
    return ((float)this->fixed_value / (float)(1 << this->fraction));
}

void    Fixed::setRawBits(int raw)
{
    this->fixed_value = raw << this->fraction;
}

std::ostream &operator << (std::ostream &output,const Fixed &input)
{
    output << input.toFloat();
    return output;
}