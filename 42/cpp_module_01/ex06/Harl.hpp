/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:00:08 by ochoumou          #+#    #+#             */
/*   Updated: 2022/10/24 16:00:09 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HARL_H_
#define _HARL_H_

#include <iostream>


class Harl 
{
    private:
        void    debug( void );
        void    info( void );
        void    warning( void );
        void    error( void );
    public:
        void    complain(std::string level);  
};

typedef void    (Harl::*complains)(void);

int     findLevel(std::string level);

#endif
