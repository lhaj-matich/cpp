#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap warrior("Tom");


    warrior.attack("Chowafa");
    warrior.takeDamage(4);
    warrior.beRepaired(5);


    return (0);
}