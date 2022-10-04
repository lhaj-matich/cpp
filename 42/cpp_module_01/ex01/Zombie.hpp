#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_
#include <iostream>

class Zombie 
{
    private:
        std::string _name;

    public:
        void    announce( void );
        void    setName(std::string name);
        ~Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif