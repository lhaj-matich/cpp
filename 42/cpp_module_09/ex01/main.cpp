#include "RPN.hpp"

int main(int argc, char **argv)
{
    try {
        RPN instance;

        if (argc < 2)
            throw RPNError("Error: please provide a valid expression.");
        instance.calculateExpression(argv[1]);
    } 
    catch (RPNError &e)
    {
        std::cout << e.what() << std::endl;
    }
}