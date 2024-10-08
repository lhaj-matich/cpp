/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:49:51 by ochoumou          #+#    #+#             */
/*   Updated: 2022/10/24 15:49:52 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

std::string const & Weapon::getType()
{
    return (type);
}

void Weapon::setType(std::string type)
{
    this->type = type;
}

Weapon::Weapon(int *type)
{
    if (type == NULL)
    {
        this->type = "Default";
        return ;
    }
}

Weapon::Weapon (std::string type)
{
    this->type = type;
}

Weapon::Weapon()
{
    std::cout << "The default constructor has been called" << std::endl;
    this->type = "Default";
}

Weapon::~Weapon()
{
    std::cout << "Weapon destroyed successfully." << std::endl;
}