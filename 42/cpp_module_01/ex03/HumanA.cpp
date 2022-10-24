/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:49:37 by ochoumou          #+#    #+#             */
/*   Updated: 2022/10/24 17:53:24 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):weapon (weapon)
{
    std::cout << "The HumanA default constrcutor has been called" << std::endl;
    this->name = name;
}

HumanA::~HumanA()
{
    std::cout << this->name << " Died piecefully." << std::endl;
}

void    HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}