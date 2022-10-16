#include "Weapon.hpp"

std::string const & Weapon::getType()
{
    return (type);
}

void Weapon::setType(std::string type)
{
    this->type = type;
}

Weapon::Weapon(char *type)
{
    if (type == NULL)
    {
        this->type = "Sword";
        return ;
    }
    this->type = type;
}

Weapon::Weapon()
{
    std::cout << "The default constructor has been called" << std::endl;
    this->type = "Sword";
}

Weapon::~Weapon()
{
    std::cout << "Weapon destroyed successfully." << std::endl;
}