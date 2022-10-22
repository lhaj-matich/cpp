/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:18:40 by ochoumou          #+#    #+#             */
/*   Updated: 2022/10/22 13:53:40 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

void    Zombie::announce( void )
{
    std::cout << _name << ": BraiiiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->_name = name;
}

Zombie* newZombie( std::string name )
{
    Zombie *zombie;

    zombie = new Zombie(name);
    return (zombie);
}

void randomChump( std::string name )
{
    Zombie zombie(name);
    zombie.announce();
}

Zombie::~Zombie()
{
    std::cout << _name <<  " Has been deleted" << std::endl;
}
