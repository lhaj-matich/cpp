#include "./Zombie.hpp"

void    Zombie::announce( void )
{
    std::cout << _name << ": BraiiiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << _name <<  " Has been deleted" << std::endl;
}