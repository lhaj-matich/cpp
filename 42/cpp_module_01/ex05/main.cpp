/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:50:10 by ochoumou          #+#    #+#             */
/*   Updated: 2022/10/24 15:50:11 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl instance;

    instance.complain("debug");
    instance.complain("Something can't be found");
    instance.complain("error");
}