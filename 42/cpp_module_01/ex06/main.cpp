#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "[ Your overreacting. Please leave before i call security. ]" << std::endl;
        return (0);
    }
    Harl instance;
    instance.complain(argv[1]);
    return (0);
}