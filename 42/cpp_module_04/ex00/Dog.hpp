#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
	public:
		// Constructors
		Dog();
		Dog(const Dog &copy);
		
		// Destructor
		~Dog();
		
		// Operators
		Dog & operator=(const Dog &assign);
		
		virtual const std::string & getType() const;
        virtual void makeSound() const;		
};

#endif