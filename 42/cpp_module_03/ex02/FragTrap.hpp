/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:09:52 by ochoumou          #+#    #+#             */
/*   Updated: 2022/11/05 12:09:53 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		// Default constructor
		FragTrap();
		FragTrap(std::string name);

		// Copy constructor
		FragTrap(const FragTrap &copy);
		
		// Destructor
		~FragTrap();
		
		// Operators
		FragTrap & operator=(const FragTrap &assign);
		// Member functions
		void	hightFivesGuys(void);
		void	attack(const std::string &);
};

#endif