#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon *weapon)
{
    this->name = name;
    this->weapon = new Weapon();
}

HumanA::~HumanA()
{
    std::cout << this->name << " Died piecefully." << std::endl;
}

void    HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}