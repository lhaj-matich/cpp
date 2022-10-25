/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:49:34 by ochoumou          #+#    #+#             */
/*   Updated: 2022/10/25 12:30:33 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    std::cout << "The HumanB default constrcutor has been called" << std::endl;
    this->name = name;
}

HumanB::~HumanB()
{
    std::cout << this->name << " Died piecefully." << std::endl;
}

void    HumanB::attack()
{
    if (this->weapon)
        std::cout << this->name << "attacks with their " << this->weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}