#include "convert.hpp"

Base *generate( void )
{
    srand(time(NULL));
    int randNum = (rand() % 3);
    Base *base;
     switch(randNum)
    {
        case 0:
            base = new A();
            break;
        case 1:
            base = new B();
            break;
        case 2:
            base = new C();
            break;
    }
    return (base);
}

void    identify(Base *p)
{
    A *ptrA;
    B *ptrB;
    C *ptrC;

    ptrA = dynamic_cast<A *>(p);
    ptrB = dynamic_cast<B *>(p);
    ptrC = dynamic_cast<C *>(p);
    if (ptrA)
        std::cout << "A" << std::endl;
    else if (ptrB)
        std::cout << "B" << std::endl;
    else if (ptrC)
        std::cout << "C" << std::endl;
    else
        std::cout << "This type is unrelated" << std::endl;
}

void    identify(Base &p)
{
    try 
    {
        A & ptrA = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)ptrA;
    }
    catch(std::exception &e)
    {
        (void)e;
    }
    try 
    {
        B & ptrB = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        (void)ptrB;
    }
    catch(std::exception &e)
    {
        (void)e;
    }
    try 
    {
        C & ptrC = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        (void)ptrC;
    }
    catch(std::exception &e)
    {
        (void)e;
    }
}

int main(void)
{
    Base *ptr = generate();
    // Testing the identify function that takes a ptr as a parameter.
    // identify(ptr);
    // Testing the indentify function that takes a ref as a parameter.
    identify(*ptr);
    delete ptr;
}