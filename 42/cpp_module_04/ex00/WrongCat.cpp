#include "WrongCat.hpp"

// Constructors
WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "\e[0;33mDefault Constructor called of WrongCat\e[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	_type = copy.getType();
	std::cout << "\e[0;33mCopy Constructor called of WrongCat\e[0m" << std::endl;
}

// Destructor
WrongCat::~WrongCat()
{
	std::cout << "\e[0;31mDestructor called of WrongCat\e[0m" << std::endl;
}

// Operators
WrongCat & WrongCat::operator=(const WrongCat &assign)
{
	_type = assign.getType();
	return *this;
}


const std::string & WrongCat::getType() const
{
	return _type;
}

void	WrongCat::makeSound() const 
{
	std::cout << "Meow Meow !!" << std::endl;
}