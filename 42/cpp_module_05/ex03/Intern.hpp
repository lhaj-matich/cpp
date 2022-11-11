#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "Form.hpp"

class Intern
{
	public:
		// Constructors
		Intern();
		Intern(const Intern &copy);
		
		// Destructor
		~Intern();
		
		// Operators
		Intern & operator=(const Intern &assign);

		class InvalidFormException : public std::exception
		{
			public:
				const char * what() const throw();
		};

		// Member functions
		Form *	makeForm(std::string formName, std::string target);
};

int findForm(std::string form);

#endif