#include "Cat.hpp"

// Constructors
Cat::Cat()
{
	_cerv = new Brain();
	_type = "Cat";
	std::cout << "\e[0;33mDefault Constructor called of Cat\e[0m" << std::endl;
}

Cat::Cat(const Cat &copy): Animal(copy)
{
	_type = copy.getType();
	std::cout << "\e[0;33mCopy Constructor called of Cat\e[0m" << std::endl;
}

// Destructor
Cat::~Cat()
{
	delete _cerv;
	std::cout << "\e[0;31mDestructor called of Cat\e[0m" << std::endl;
}


// Operators
Cat & Cat::operator=(const Cat &assign)
{
	_type = assign.getType();
	_cerv = new Brain(*assign._cerv);
	return *this;
}


// Member function
const std::string & Cat::getType() const
{
	return _type;
}

void	Cat::makeSound() const 
{
	std::cout << "Meow Meow !!" << std::endl;
}