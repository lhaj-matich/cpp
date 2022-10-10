/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:48:30 by ochoumou          #+#    #+#             */
/*   Updated: 2022/10/09 13:01:30 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WEAPON_H_
#define _WEAPON_H_

#include <iostream>

class Weapon 
{
    private:
        std::string type;
    public:
        std::string const & getType();
        void setType(std::string type);
        Weapon(std::string type);
        Weapon();
        ~Weapon();
};

#endif