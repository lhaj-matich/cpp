#include <iostream>
#include "Weapon.hpp"

#ifndef __HUMANA_H_
#define __HUMANA_H_
 
class HumanA 
{
    private:
        Weapon *weapon;
        std::string name;
    public:
        HumanA(std::string, Weapon);
        ~HumanA();
        void    attack();
       
};

#endif