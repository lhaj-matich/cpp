#include "RPN.hpp"

int main(int argc, char **argv)
{
    RPN instance;

    // instance.calculateExpression("8 9 * 9 - 9 - 9 - 4 - 1 +");
    try {
        instance.calculateExpression("7 7 * 7 -");
        instance.calculateExpression("1 2 * 2 / 2 * 2 4 - +");
        instance.calculateExpression("1 + 1");
    } catch (std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }
}