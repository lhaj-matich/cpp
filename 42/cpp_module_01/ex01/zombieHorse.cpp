#include "Zombie.hpp"

void    Zombie::setName(std::string name)
{
    _name = name;
}

Zombie* zombieHorde( int N, std::string name )
{
    int i;
    Zombie *zombieBunch = new Zombie[N];

    i = 0;
    while (i < N)
    {
        zombieBunch[i].setName(name);
        zombieBunch[i].announce();
        i++;
    }
    return zombieBunch;
}