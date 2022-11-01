#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{
    std::cout << "Default constructor of bureaucrat called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    std::cout << "Field constructor of bureaucrat called." << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor of bureaucrat called." << std::endl;
}

// Bureaucrat member functions.

void    Bureaucrat::incrementGrade()
{
    if (this->_grade <= 1) // High grade
        throw Bureaucrat::GradeTooHighException();
    this->_grade -= 1;
}

void    Bureaucrat::decrementGrade()
{
    if (this->_grade >= 150) // High grade
        throw Bureaucrat::GradeTooLowException();
    this->_grade += 1;
}

// Get private variables

int Bureaucrat::getGrade()
{
    return (this->_grade);
}

std::string Bureaucrat::getName()
{
    return (this->_name);
}

// Exceptions

const char *Bureaucrat::GradeTooLowException::what() const throw() 
{
    return "TooHighException";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "TooLowException";
}

// Overload the output operator

std::ostream & operator<<(std::ostream & output, Bureaucrat & input)
{
    output << input.getName() << ", bureaucrat grade " << input.getGrade() << ".";
    return output;
}