#include "Fixed.hpp"

int main(void)
{
    {
        Fixed a;

        Fixed b(a); // b = a; both of these declarations will call the copy constructor.

        std::cout << "Object a: " << &a << std::endl;
        std::cout << "Object b: " << &b << std::endl;
    }

    {
        Fixed a;
        Fixed b;
        Fixed c;

        a.operator=(b);
        
        a = b;  // Translates to a.operator= (b) we should overload this operator meaning that we
        // should implement our own function.
    }



    return (0);
}