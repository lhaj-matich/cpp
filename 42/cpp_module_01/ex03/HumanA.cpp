#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
{
    std::cout << "Constructor called" << std::endl;
    this->name = name;
    this->weapon = &weapon;
}

HumanA::~HumanA()
{
    std::cout << this->name << " Died piecefully." << std::endl;
}

void    HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}