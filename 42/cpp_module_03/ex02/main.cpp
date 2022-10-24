#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap warrior("Tom");
    ScavTrap robot("Home");    

    warrior.attack("Chowafa");
    warrior.takeDamage(4);
    warrior.beRepaired(5);

    robot.guardGate();
    robot.attack("Kheow");
    return (0);
}