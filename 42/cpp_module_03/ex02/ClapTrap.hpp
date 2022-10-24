#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	public:
		// Constructors
		ClapTrap();
		ClapTrap(const ClapTrap &copy);
		ClapTrap(std::string name);
		
		// Destructor
		~ClapTrap();
		
		// Operators
		ClapTrap & operator=(const ClapTrap &assign);
		
		// Member functions

		void	attack(const std::string &);
		void	takeDamage(unsigned int);
		void	beRepaired(unsigned int);
		
	protected:
		std::string _name;
		int _health;
		int _energy;
		int _damage;
		
};

#endif