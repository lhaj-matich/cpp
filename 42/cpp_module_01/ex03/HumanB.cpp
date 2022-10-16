#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    std::cout << "The HumanB default constrcutor has been called" << std::endl;
    this->name = name;
}

HumanB::~HumanB()
{
    std::cout << this->name << " Died piecefully." << std::endl;
}

void    HumanB::attack()
{
    std::cout << this->name << "attacks with their " << this->weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}