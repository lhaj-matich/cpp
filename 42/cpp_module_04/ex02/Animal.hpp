#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	public:
		// Constructors
		Animal();
		Animal(std::string type);

		// Copy constructor
		Animal(const Animal &copy);
		
		// Destructor
		virtual ~Animal();
		
		// Copy assigment operator overload
		Animal & operator=(const Animal &assign);
		
		// Member functions

		const std::string & getType() const;
		virtual void makeSound() const = 0;
		
	protected:
		std::string _type;
		
};

#endif