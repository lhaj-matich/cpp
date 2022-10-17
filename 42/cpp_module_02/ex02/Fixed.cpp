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

Fixed & Fixed::operator+(const Fixed &rhs)
{
    this->fixed_value = this->toFloat() + rhs.toFloat();
    return (*this);
}

Fixed & Fixed::operator-(const Fixed &rhs)
{
    this->fixed_value = this->toFloat() - rhs.toFloat();
    return (*this);
}

Fixed & Fixed::operator/(const Fixed &rhs)
{
    this->fixed_value = this->toFloat() / rhs.toFloat();
    return (*this);
}

Fixed & Fixed::operator*(const Fixed &rhs)
{
    this->fixed_value = this->toFloat() * rhs.toFloat();
    return (*this);
}

Fixed & Fixed::operator++(void)
{
    int i;

    i = this->toInt();
    this->fixed_value += ++i;
    return (*this);
}

Fixed & Fixed::operator++(int)
{
    int i;

    i = this->toInt();
    this->fixed_value += i++;
    return (*this);
}

Fixed & Fixed::operator--(void)
{
    int i;

    i = this->toInt();
    this->fixed_value = --i;
    return (*this);
}

Fixed & Fixed::operator--(int)
{
    int i;

    i = this->toInt();
    this->fixed_value = i--;
    return (*this);
}

static Fixed & min(Fixed & lhs, Fixed & rhs) 
{
    if (lhs.getRawBits() > rhs.getRawBits())
        return (rhs);
    return (lhs);
}

// static const Fixed & min(const Fixed &lhs, const Fixed &rhs) 
// {
//     if (lhs.getRawBits() > rhs.getRawBits())
//         return (rhs);
//     return (lhs);
// }

static Fixed & max(Fixed &lhs, Fixed &rhs) 
{
    if (lhs.getRawBits() > rhs.getRawBits())
        return (lhs);
    return (rhs);
}

// static const Fixed & max(const Fixed &lhs,const Fixed &rhs) 
// {
//     if (lhs.getRawBits() > rhs.getRawBits())
//         return (lhs);
//     return (rhs);
// }