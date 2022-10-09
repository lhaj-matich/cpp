#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
}

HumanB::~HumanB()
{
    std::cout << this->name << " Died piecefully." << std::endl;
}

void    HumanB::attack()
{
    std::cout << this->name << "attacks with their " << this->weapon.getType() << std::endl;
}

void    HumanB::setWeapon(Weapon weapon)
{
    this->weapon = weapon;
}