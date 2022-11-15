#include <iostream>
#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed b(a);
    // Fixed b = a;
    b = a;
    // std::cout << b << std::endl;
    std::cout << "fine" << std::endl;
    // Fixed c;

    // c = b;

    // std::cout << a.getRawBits() << std::endl;
    // std::cout << b.getRawBits() << std::endl;
    // std::cout << c.getRawBits() << std::endl;

    return (0);
}