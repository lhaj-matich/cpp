#ifndef _FIXED_H_
#define _FIXED_H_

#include <iostream>

class Fixed 
{
    private:
        int fixed_value;
        static const int fraction = 8;
    public:
        Fixed(); // Default constructor
        ~Fixed(); // Default deconstructor
        Fixed(const Fixed &other); // Copy constructor
        Fixed & operator=(const Fixed &rhs); // Overload the copy constructor

        int getRawBits() const;
        void    setRawBits(int raw);
};


#endif