#include "WrongAnimal.hpp"

// Constructors
WrongAnimal::WrongAnimal()
{
	this->_type = "";
	std::cout << "\e[0;33mDefault Constructor called of WrongAnimal\e[0m" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->_type = type;
	std::cout << "\e[0;33mField Constructor called of WrongAnimal\e[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	_type = copy.getType();
	std::cout << "\e[0;33mCopy Constructor called of WrongAnimal\e[0m" << std::endl;
}

// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "\e[0;31mDestructor called of WrongAnimal\e[0m" << std::endl;
}

const std::string & WrongAnimal::getType() const
{
	return _type;
}

// Operators
WrongAnimal & WrongAnimal::operator=(const WrongAnimal &assign)
{
	_type = assign.getType();
	return *this;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "I don't have a sound yet" << std::endl;
}