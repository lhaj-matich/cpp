/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:00:05 by ochoumou          #+#    #+#             */
/*   Updated: 2022/10/24 16:00:06 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int findLevel(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
    {
        if (!strcmp(levels[i].c_str(), level.c_str()))
            return (i);
    }
    return (4);
}

void    Harl::debug()
{
    std::cout << "[ DEBUG ]" << std::endl;;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do !" << std::endl;
}

void    Harl::info()
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void    Harl::warning()
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error()
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable ! I want to speak to the manager now" << std::endl;
}

void    Harl::complain(std::string level)
{
    complains functions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    int lvl;
    
    lvl = findLevel(level);
    switch (lvl)
    {
        case 0:
            (this->*functions[0])();
        case 1:
            (this->*functions[1])();
        case 2:
            (this->*functions[2])();
        case 3:
            (this->*functions[3])();
        break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
}