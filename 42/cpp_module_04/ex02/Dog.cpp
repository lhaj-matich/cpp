#include "Dog.hpp"

// Constructors
Dog::Dog()
{
	_type = "Dog";
	_cerv = new Brain();
	std::cout << "\e[0;33mDefault Constructor called of Dog\e[0m" << std::endl;
}

Dog::Dog(const Dog &copy): Animal(copy)
{
	_type = copy.getType();
	_cerv = copy._cerv;
	std::cout << "\e[0;33mCopy Constructor called of Dog\e[0m" << std::endl;
}

// Destructor
Dog::~Dog()
{
	delete _cerv;
	std::cout << "\e[0;31mDestructor called of Dog\e[0m" << std::endl;
}

// Operators
Dog & Dog::operator=(const Dog &assign)
{
	if (_cerv)
		delete _cerv;
	_type = assign.getType();
	_cerv = new Brain(*assign._cerv);
	return *this;
}

// Member functions
const std::string & Dog::getType() const
{
	return _type;
}

void    Dog::makeSound() const 
{
    std::cout << "Arf Arf !!!" << std::endl;
}