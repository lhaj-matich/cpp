#include "Form.hpp"

// Constructors
Form::Form(): _name("")
{
	_is_signed = false;
	_sign_grade = 1;
	_exec_grade = 1;
	std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;
}

Form::Form(const Form &copy): _name(copy._name)
{
	_is_signed = copy.getIs_signed();
	_sign_grade = copy.getSign_grade();
	_exec_grade = copy.getExec_grade();
	if (_exec_grade > 150 || _sign_grade > 150)
		throw Form::GradeTooLowExecption();
	if (_exec_grade < 1 || _sign_grade < 1)
		throw Form::GradeTooHighExecption();
	std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;
}

Form::Form(std::string name, bool is_signed, int sign_grade, int exec_grade) : _name(name)
{
	_sign_grade = sign_grade;
	_exec_grade = exec_grade;
	if (_exec_grade > 150 || _sign_grade > 150)
		throw Form::GradeTooLowExecption();
	if (_exec_grade < 1 || _sign_grade < 1)
		throw Form::GradeTooHighExecption();
	_is_signed = is_signed;
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
	_exec_grade = assign.getExec_grade();
	_sign_grade = assign.getSign_grade();
	if (_exec_grade > 150 || _sign_grade > 150)
		throw Form::GradeTooLowExecption();
	if (_exec_grade < 1 || _sign_grade < 1)
		throw Form::GradeTooHighExecption();
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

// Member functions

void	Form::beSigned(Bureaucrat & bureaucrat)
{
	if (bureaucrat.getGrade() > 150)
		throw Form::GradeTooLowExecption();
	this->_is_signed = true;
}

// Operator overload

std::ostream &operator<<(std::ostream &output, const Form & input)
{
	output << input.getName() << ", signed: " << input.getIs_signed() << " signed grade: " << input.getSign_grade() << " execution grade: " << input.getExec_grade();
	return output;
}