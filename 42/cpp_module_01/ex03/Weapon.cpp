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

Weapon::~Weapon()
{
    std::cout << "Weapon destroyed successfully." << std::endl;
}

Weapon::Weapon()
{
    this->type = "7ajra";
}