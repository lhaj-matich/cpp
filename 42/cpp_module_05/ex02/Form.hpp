#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Form
{
	public:
		// Constructors
		Form();
		Form(const Form &copy);
		Form(std::string name, int sign_grade, int exec_grade);
		
		// Destructor
		virtual ~Form();
		
		// Operators
		Form & operator=(const Form &assign);
		
		// Execeptions
		class GradeTooHighExecption : public std::exception 
		{
			public:
				const char * what() const throw();
		};

		class GradeTooLowExecption: public std::exception 
		{
			public:
				const char *what() const throw();
		};

		// Member functions (Getters)
		std::string getName() const;
		bool getIs_signed() const;
		int getSign_grade() const;
		int getExec_grade() const;

		// Member functions (Bureaucrat)
		void	beSigned(Bureaucrat &);
		virtual void	procedure() const = 0;
	private:
		const std::string _name;
		bool _is_signed;
		int _sign_grade;
		int _exec_grade;
};

std::ostream operator<<(std::ostream output, const Form & input);

#endif