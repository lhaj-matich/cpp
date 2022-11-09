/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:04:55 by ochoumou          #+#    #+#             */
/*   Updated: 2022/11/09 13:02:04 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructors
Form::Form(): _name(""), _sign_grade(1) , _exec_grade(1)
{
	_is_signed = false;
	std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;
}

Form::Form(const Form &copy): _name(copy._name), _sign_grade(copy._sign_grade) , _exec_grade(copy._exec_grade)
{
	_is_signed = copy.getIs_signed();
	if (_exec_grade > 150 || _sign_grade > 150)
		throw Form::GradeTooLowExecption();
	if (_exec_grade < 1 || _sign_grade < 1)
		throw Form::GradeTooHighExecption();
	std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;
}

Form::Form(std::string name, int sign_grade, int exec_grade) : _name(name), _sign_grade(sign_grade) , _exec_grade(exec_grade)
{
	if (_exec_grade > 150 || _sign_grade > 150)
		throw Form::GradeTooLowExecption();
	if (_exec_grade < 1 || _sign_grade < 1)
		throw Form::GradeTooHighExecption();
	_is_signed = false;
	std::cout << "\e[0;33mFields Constructor called of Form\e[0m" << std::endl;
}


// Destructor
Form::~Form()
{
	std::cout << "\e[0;31mDestructor called of Form\e[0m" << std::endl;
}

// Operators
Form & Form::operator=(const Form &assign)
{
	_is_signed = assign.getIs_signed();
	return *this;
}

// Exceptions

const char * Form::GradeTooHighExecption::what() const throw() 
{
	return ("GradeTooHighException");
}

const char * Form::GradeTooLowExecption::what() const throw() 
{
	return ("GradeTooLowException");
}

const char * Form::FormNotSignedException::what() const throw()
{
	return ("FormNotSignedException");
}

// Member functions to get the values
std::string Form::getName() const
{
	return _name;
}
bool Form::getIs_signed() const
{
	return _is_signed;
}
int Form::getSign_grade() const
{
	return _sign_grade;
}
int Form::getExec_grade() const
{
	return _exec_grade;
}

void	Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > this->_sign_grade)
		throw Form::GradeTooLowExecption();
	this->_is_signed = true;
}

void	Form::execute(Bureaucrat const & executor) const 
{
	if (!this->_is_signed)
		throw Form::FormNotSignedException();
	if (executor.getGrade() > 150)
		throw Form::GradeTooLowExecption();
	if (executor.getGrade() < 1)
		throw Form::GradeTooHighExecption();
	this->procedure();
}

std::ostream &operator<<(std::ostream &output, const Form & input)
{
	output << input.getName() << ", signed: " << input.getIs_signed() << " signed grade: " << input.getSign_grade() << " execution grade: " << input.getExec_grade();
	return output;
}