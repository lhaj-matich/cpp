/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:09:55 by ochoumou          #+#    #+#             */
/*   Updated: 2022/11/05 12:09:56 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap warrior("Tom");
    ScavTrap robot("Home");    

    warrior.attack("Chowafa");
    warrior.takeDamage(4);
    warrior.beRepaired(5);

    robot.guardGate();
    robot.attack("Kheow");
    return (0);
}