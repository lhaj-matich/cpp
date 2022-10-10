#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl instance;

    instance.complain("debug");
    instance.complain("Something can't be found");
    instance.complain("error");
}