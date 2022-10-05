#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_
#include <iostream>

class Zombie 
{
    private:
        std::string _name;

    public:
        void    announce( void );
        Zombie(std::string name);
        ~Zombie();
};

Zombie* newZombie( std::string name );
void    randomChump( std::string name );

#endif