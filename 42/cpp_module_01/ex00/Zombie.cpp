#include "./Zombie.hpp"

void    Zombie::announce( void )
{
    std::cout << _name << ": BraiiiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie( std::string name )
{
    Zombie *zombie;

    zombie = new Zombie(name);
    return (zombie);
}

void randomChump( std::string name )
{
    Zombie zombie(name);

    zombie.announce();
}

Zombie::~Zombie()
{
    std::cout << _name <<  " Has been deleted" << std::endl;
}
