/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:49:44 by ochoumou          #+#    #+#             */
/*   Updated: 2022/10/24 15:49:45 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        void    setWeapon(Weapon &weapon);
        void    attack();
};

#endif