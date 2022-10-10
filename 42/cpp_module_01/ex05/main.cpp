#include <iostream>
#include "Harl.hpp"

int main(void)
{
    Harl instance;

    instance.complain("debug");
    instance.complain("Something");
    instance.complain("info");
    instance.complain("error");
    return (0); 
}