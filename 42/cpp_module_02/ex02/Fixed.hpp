#ifndef _FIXED_H_
#define _FIXED_H_

#include <iostream>
#include <cmath>

class Fixed 
{
    private:
        int fixed_value;
        static const int fraction = 8;
    public:
        Fixed(int);
        Fixed(float);
        Fixed();
        ~Fixed();
        Fixed(const Fixed &other);
        Fixed & operator=(Fixed const &rhs);

        int     getRawBits() const;
        int     toInt(void) const;
        void    setRawBits(int raw);
        float   toFloat(void) const;
        // Comparason operators.
        bool    operator>(const Fixed &rhs) const;
        bool    operator<(const Fixed &rhs) const;
        bool    operator<= (const Fixed &rhs) const;
        bool    operator>= (const Fixed &rhs) const;
        bool    operator== (const Fixed &rhs) const;
        bool    operator!= (const Fixed &rhs) const;
        // Arithmetic operators.
        Fixed operator+(Fixed const &rhs);
        Fixed operator-(Fixed const &rhs);
        Fixed operator/(Fixed const &rhs);
        Fixed operator*(Fixed const &rhs);

        // Increment and decrement operators.
        Fixed   operator++(int);
        Fixed & operator++();
        Fixed   operator--(int);
        Fixed & operator--();
        static Fixed & min(Fixed &, Fixed &);
        static const Fixed & min(Fixed const & value1, Fixed const & value2);

        static const Fixed & max(Fixed const & value1, Fixed const & value2);
        static Fixed & max(Fixed & value1, Fixed & value2);
};

std::ostream &operator << (std::ostream &output,const Fixed &input);

#endif