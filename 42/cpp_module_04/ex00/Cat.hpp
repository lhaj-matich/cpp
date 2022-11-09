# ifndef CAT_HPP_
# define CAT_HPP_

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{
	public:
		// Constructors
		Cat();
		Cat(std::string type);
		Cat(const Cat &copy);
		
		// Destructor
		~Cat();
		
		// Operators
		Cat & operator=(const Cat &assign);
		
		// Member functions
		const std::string & getType() const;
        void    makeSound() const;
};

#endif