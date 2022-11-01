#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Bureaucrat
{
	private:
		std::string const name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat (std::string const &name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();
		Bureaucrat & operator=(const Bureaucrat &assign);

        class GradeTooHighException: public std::exception 
        {
            const char* what() const throw();
        };
        class GradeTooLowException: public std::exception 
        {
            const char* what(void) const throw();
        };

		std::string getName (void) const;
		int getGrade (void) const;
		void incrementGrade (void);
		void decrementGrade (void);

        void    Bureaucrat::signForm(Form &form);
};

std::ostream& operator << (std::ostream &o, Bureaucrat const &obj);

#endif