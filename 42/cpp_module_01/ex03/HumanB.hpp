#include <iostream>
#include "Weapon.hpp"

#ifndef __HUMANB_H_
#define __HUMANB_H_

class HumanB
{
    private:
        Weapon *weapon;
        std::string name;
    public:
        HumanB(std::string name);
        ~HumanB();
        void    setWeapon(Weapon weapon);
        void    attack();
};

#endif