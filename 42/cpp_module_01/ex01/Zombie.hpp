/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:18:57 by ochoumou          #+#    #+#             */
/*   Updated: 2022/10/22 13:18:58 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_
#include <iostream>

class Zombie 
{
    private:
        std::string _name;

    public:
        void    announce( void );
        void    setName(std::string name);
        ~Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif