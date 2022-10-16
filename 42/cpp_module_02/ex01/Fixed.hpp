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
};

std::ostream &operator << (std::ostream &output,const Fixed &input);

#endif