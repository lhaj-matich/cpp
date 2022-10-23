#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap()
{
	_name = "";
	_health = 10;
	_energy = 10;
	_damage = 0;
	std::cout << "\e[0;33mDefault Constructor called of ClapTrap\e[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	_name = copy._name;
	_health = copy._health;
	_energy = copy._energy;
	_damage = copy._damage;
	std::cout << "\e[0;33mCopy Constructor called of ClapTrap\e[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_health = 10;
	_energy = 10;
	_damage = 0;
	std::cout << "\e[0;33mFields Constructor called of ClapTrap\e[0m" << std::endl;
}


// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "\e[0;31mDestructor called of ClapTrap\e[0m" << std::endl;
}


// Copy assign operator overload
ClapTrap & ClapTrap::operator=(const ClapTrap &assign)
{
	_name = assign._name;
	_health = assign._health;
	_energy = assign._energy;
	_damage = assign._damage;
	return *this;
}


// Member functions

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energy > 0 && this->_health > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target <<
		", causing " << this->_damage << " points of damage!" << std::endl;
		this->_energy -= 1;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_energy > 0 && this->_health > 0)
	{
		std::cout << "ClapTrap " << this->_name << " was attacked which led him to be damaged by " << amount << " points!" << std::endl;
		this->_health -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy > 0 && this->_health > 0)
	{
		std::cout << "ClapTrap " << this->_name << " recovered " << amount << " hit points!" << std::endl;
		this->_energy -= 1;
		this->_health += amount;
	}
}
