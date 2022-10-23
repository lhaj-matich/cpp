#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):weapon (weapon)
{
    std::cout << "The HumanA default constrcutor has been called" << std::endl;
    this->name = name;
}

HumanA::~HumanA()
{
    std::cout << this->name << " Died piecefully." << std::endl;
}

void    HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}