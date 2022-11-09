#ifndef WRONGANIMAL_HPP_
# define WRONGANIMAL_HPP_

# include <iostream>
# include <string>

class WrongAnimal
{
	public:
		// Constructors
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &copy);
		
		// Destructor
		~WrongAnimal();
		
		// Operators
		WrongAnimal & operator=(const WrongAnimal &assign);
		
		const std::string & getType() const;
		void makeSound() const;
	protected:
		std::string _type;
		
};

#endif