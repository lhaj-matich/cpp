/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:19:00 by ochoumou          #+#    #+#             */
/*   Updated: 2022/10/22 13:19:01 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void    Zombie::setName(std::string name)
{
    _name = name;
}

Zombie* zombieHorde( int N, std::string name )
{
    int i;
    Zombie *zombieBunch = new Zombie[N];

    i = 0;
    while (i < N)
    {
        zombieBunch[i].setName(name);
        i++;
    }
    return zombieBunch;
}