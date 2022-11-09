#ifndef WRONGCAT_HPP_
# define WRONGCAT_HPP_

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		// Constructors
		WrongCat();
		WrongCat(const WrongCat &copy);
		
		// Destructor
		~WrongCat();
		
		// Operators
		WrongCat & operator=(const WrongCat &assign);
		
		// Member functions
		const std::string & getType() const;
        void    makeSound() const;
};

#endif