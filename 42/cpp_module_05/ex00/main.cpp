#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
    {
        try 
        {
            Bureaucrat bureaucat("Chowafa", 30);
            std::cout << bureaucat << std::endl;
            bureaucat.decrementGrade();
            std::cout << bureaucat << std::endl;
            bureaucat.decrementGrade();
            std::cout << bureaucat << std::endl;
            bureaucat.decrementGrade();
            std::cout << bureaucat << std::endl;
            bureaucat.decrementGrade();
            std::cout << bureaucat << std::endl;
        }
        catch(std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "=======================" << std::endl;
    {
        try 
        {
            Bureaucrat bureaucat("Chowafa", 150);
            std::cout << bureaucat << std::endl;
            bureaucat.decrementGrade();
            std::cout << bureaucat << std::endl;
            bureaucat.decrementGrade();
            std::cout << bureaucat << std::endl;
            bureaucat.decrementGrade();
            std::cout << bureaucat << std::endl;
            bureaucat.decrementGrade();
            std::cout << bureaucat << std::endl;
        }
        catch(std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}
