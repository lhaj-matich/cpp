/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:49:41 by ochoumou          #+#    #+#             */
/*   Updated: 2022/10/24 17:53:16 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

#ifndef __HUMANA_H_
#define __HUMANA_H_
 
class HumanA 
{
    private:
        Weapon &weapon;
        std::string name;
    public:
        HumanA(std::string, Weapon &);
        ~HumanA();
        void    attack();
       
};

#endif