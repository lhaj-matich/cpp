#ifndef _FIXED_H_
#define _FIXED_H_

#include <iostream>

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
        Fixed & operator=(const Fixed &rhs);

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
        Fixed & operator+(const Fixed &rhs);
        Fixed & operator-(const Fixed &rhs);
        Fixed & operator/(const Fixed &rhs);
        Fixed & operator*(const Fixed &rhs);

        // Increment and decrement operators.
        Fixed & operator++(int);
        Fixed & operator++();
        Fixed & operator--(int);
        Fixed & operator--();
        static Fixed & min(Fixed & lhs, Fixed & rhs);
        // static const Fixed & min(const Fixed & lhs, const Fixed & rhs);
        // static const Fixed & max(const Fixed & lhs, const Fixed & rhs);
        static Fixed & max(Fixed & lhs, Fixed & rhs);
};

std::ostream &operator << (std::ostream &output,const Fixed &input);

#endif