/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:19:39 by ochoumou          #+#    #+#             */
/*   Updated: 2022/10/22 12:38:57 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

int main(void)
{
    Zombie *table;
    
    table = zombieHorde(5, "soleeee");

    for (int i = 0; i < 5;i++)
        table[i].announce();
    delete [] table;
    return (0);   
}