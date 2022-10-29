#include "Brain.hpp"

// Constructors
Brain::Brain()
{
	std::cout << "\e[0;33mDefault Constructor called of Brain\e[0m" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::string *ideastable = copy.getIdeas();
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = ideastable[i];
	std::cout << "\e[0;33mCopy Constructor called of Brain\e[0m" << std::endl;
}

// Destructor
Brain::~Brain()
{
	std::cout << "\e[0;31mDestructor called of Brain\e[0m" << std::endl;
}

// Overload the copy assign operator
Brain & Brain::operator=(const Brain &assign)
{
	std::string *ideastable = assign.getIdeas();
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = ideastable[i];
	return *this;
}

// Member functions 
std::string *Brain::getIdeas() const
{
	return (std::string *)this->_ideas;
}
