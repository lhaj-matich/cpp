#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>

class RobotomyRequestForm
{
	public:
		// Constructors
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		
		// Destructor
		~RobotomyRequestForm();
		
		// Operators
		RobotomyRequestForm & operator=(const RobotomyRequestForm &assign);
		
	private:
		
};

#endif