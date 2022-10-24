/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:00:11 by ochoumou          #+#    #+#             */
/*   Updated: 2022/10/24 16:00:12 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "[ Your overreacting. Please leave before i call security. ]" << std::endl;
        return (0);
    }
    Harl instance;
    instance.complain(argv[1]);
    return (0);
}