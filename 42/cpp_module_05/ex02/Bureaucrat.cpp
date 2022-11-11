/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:04:50 by ochoumou          #+#    #+#             */
/*   Updated: 2022/11/11 21:20:47 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

Bureaucrat::Bureaucrat(Bureaucrat const & copy) : _name(copy._name)
{
    this->_grade = copy._grade;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & assign)
{
    this->_grade = assign._grade;
    return (*this);
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

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

std::string Bureaucrat::getName() const
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

void    Bureaucrat::signForm(Form &form)
{
    try 
    {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void    Bureaucrat::executeForm(Form const & form)
{
    try 
    {
        form.execute(*this);
        std::cout << this->_name << " executed " << form.getName() << std::endl; 
    }
    catch(std::exception &e)
    {
        (void)e;
        std::cout << this->_name << " could not execute this form." << std::endl;
    }
}