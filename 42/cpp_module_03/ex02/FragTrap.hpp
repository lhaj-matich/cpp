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