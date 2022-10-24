#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap()
{
	_name = "Default";
	_health = 100;
	_energy = 50;
	_damage = 20;
	std::cout << "\e[0;33mDefault Constructor called of ScavTrap\e[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	_name = name;
	_health = 100;
	_energy = 50;
	_damage = 20;
	std::cout << "\e[0;33mField Constructor called of ScavTrap\e[0m" << std::endl;
}


ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	_name = copy._name;
	_health = copy._health;
	_energy = copy._energy;
	_damage = copy._damage;
	std::cout << "\e[0;33mCopy Constructor called of ScavTrap\e[0m" << std::endl;
}


// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "\e[0;31mDestructor called of ScavTrap\e[0m" << std::endl;
}

ScavTrap & ScavTrap::operator=(const ScavTrap &assign)
{
	_name = assign._name;
	_health = assign._health;
	_energy = assign._energy;
	_damage = assign._damage;
	return *this;
}

// Member functions

void	ScavTrap::attack(const std::string & target)
{
	if (this->_energy > 0 && this->_health > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target <<
		", causing " << this->_damage << " points of damage!" << std::endl;
		this->_energy -= 1;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}