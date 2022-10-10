#include "Weapon.hpp"

std::string const & Weapon::getType()
{
    return (type);
}

void Weapon::setType(std::string type)
{
    this->type = type;
}

Weapon::Weapon(std::string type)
{ 
    this->type = type;
}

Weapon::Weapon()
{
    this->type = "Sword";
}

Weapon::~Weapon()
{
    std::cout << "Weapon destroyed successfully." << std::endl;
}