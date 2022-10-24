#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		// Constructors
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &copy);
		
		// Destructor
		~ScavTrap();
		
		// Operators
		/// @brief  Copy assign operator overload
		/// @param assign 
		/// @return refrence to the current instance
		ScavTrap & operator=(const ScavTrap &assign);
		
		// Members functions

		void	guardGate();
		void	attack(const std::string &);
};

#endif