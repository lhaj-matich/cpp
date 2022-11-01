#include "Cat.hpp"

// Constructors
Cat::Cat()
{
	_type = "Cat";
	_b_
	std::cout << "\e[0;33mDefault Constructor called of Cat\e[0m" << std::endl;
}

Cat::Cat(const Cat &copy)
{
	_type = copy.getType();
	std::cout << "\e[0;33mCopy Constructor called of Cat\e[0m" << std::endl;
}

// Destructor
Cat::~Cat()
{
	std::cout << "\e[0;31mDestructor called of Cat\e[0m" << std::endl;
}


// Operators
Cat & Cat::operator=(const Cat &assign)
{
	_type = assign.getType();
	return *this;
}


// Getters / Setters
const std::string & Cat::getType() const
{
	return _type;
}

void	Cat::makeSound() const 
{
	std::cout << "Meow Meow !!" << std::endl;
}