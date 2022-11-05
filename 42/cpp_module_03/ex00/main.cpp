/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:09:26 by ochoumou          #+#    #+#             */
/*   Updated: 2022/11/05 12:09:27 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap warrior("Tom");


    warrior.attack("Chowafa");
    warrior.takeDamage(4);
    warrior.beRepaired(5);


    return (0);
}