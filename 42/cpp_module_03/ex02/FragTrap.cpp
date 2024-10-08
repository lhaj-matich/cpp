/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:09:49 by ochoumou          #+#    #+#             */
/*   Updated: 2022/11/05 12:09:50 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap()
{
	this->_name = "Default";
	this->_health = 100;
	this->_energy = 100;
	this->_damage = 30;
	std::cout << "\e[0;33mDefault Constructor called of FragTrap\e[0m" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->_name = name;
	this->_health = 100;
	this->_energy = 100;
	this->_damage = 30;
	std::cout << "\e[0;33mDefault Constructor called of FragTrap\e[0m" << std::endl;
}

// Copy constructor

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	_name = copy._name;
	_health = copy._health;
	_energy = copy._energy;
	_damage = copy._damage;
	std::cout << "\e[0;33mCopy Constructor called of FragTrap\e[0m" << std::endl;
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "\e[0;31mDestructor called of FragTrap\e[0m" << std::endl;
}

// Operators
FragTrap & FragTrap::operator=(const FragTrap &assign)
{
	_name = assign._name;
	_health = assign._health;
	_energy = assign._energy;
	_damage = assign._damage;
	return *this;
}

// Member funtuions
void	FragTrap::hightFivesGuys(void)
{
	std::cout << "Requesting high five!!!" << std::endl; 
}

void	FragTrap::attack(const std::string & target)
{
	if (this->_energy > 0 && this->_health > 0)
	{
		std::cout << "FragTrap " << this->_name << " attacks " << target <<
		", causing " << this->_damage << " points of damage!" << std::endl;
		this->_energy -= 1;
	}
}