#include "Bureaucrat.hpp"

void    Bureaucrat::signForm(Form &form) 
{
    if (form.getIs_signed())
        std::cout << this->name << " signed " << form.getName() << std::endl;
    else
        std::cout << this->name << " couldn't sign " << form.getName() << " because grade is too low" << std::endl;
}

Bureaucrat::Bureaucrat():name ("Default Bereacrat"), grade (1)
{
	std::cout << "\e[0;33mDefault Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade):name (name)
{
	std::cout << "\e[0;32mParameterConstructor called of Bureaucrat\e[0m" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = grade ;
}

void Bureaucrat::incrementGrade (void)
{
	if (this->grade  - 1 < 1)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		this->grade--;
	}
}

void Bureaucrat::decrementGrade (void)
{
	if (this->grade   + 1 > 150)
		throw Bureaucrat::GradeTooHighException();
	else
	{
		this->grade++;
	}
}

int Bureaucrat::getGrade (void) const
{
	return (this->grade);
}

std::string Bureaucrat::getName (void) const
{
	return (this->name);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy):name (copy.name)
{
	std::cout << "\e[0;33mCopy Constructor called of Bureaucrat\e[0m" << std::endl;
	this->grade = copy.grade;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;31mDestructor called of Bureaucrat\e[0m" << std::endl;
}

// Operators
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &assign)
{
	this->grade = assign.grade;
	return *this;
}

const char * Bureaucrat::GradeTooHighException::what (void) const throw ()
{
	return ("GradeTooHighException");
}

const char * Bureaucrat::GradeTooLowException::what (void) const throw ()
{
	return ("GradeTooLowException");
}

std::ostream& operator << (std::ostream &o, Bureaucrat const &obj)
{
	o << obj.getName() << ", Bureaucrat Grade " << obj.getGrade() << std::endl;
	return (o);
}