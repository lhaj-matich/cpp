#include "Animal.hpp"

// Constructors
Animal::Animal()
{
	_type = "";
	std::cout << "\e[0;33mDefault Constructor called of Animal\e[0m" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	_type = copy.getType();
	std::cout << "\e[0;33mCopy Constructor called of Animal\e[0m" << std::endl;
}

Animal::Animal(std::string type)
{
	_type = type;
	std::cout << "\e[0;33mFields Constructor called of Animal\e[0m" << std::endl;
}


// Destructor
Animal::~Animal()
{
	std::cout << "\e[0;31mDestructor called of Animal\e[0m" << std::endl;
}


// Operators
Animal & Animal::operator=(const Animal &assign)
{
	std::cout << "\e[0;31mCopy assign operator overload of Animal\e[0m" << std::endl;
	_type = assign.getType();
	return *this;
}


// Member functions

const std::string & Animal::getType() const
{
	return _type;
}

void	Animal::makeSound() const 
{
	std::cout << "I don't have a sound yet!" << std::endl;
}