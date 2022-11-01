#include "Bureaucrat.hpp"

void    Bureaucrat::signForm(Form &form) 
{
    if (form.getIs_signed())
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    else
        std::cout << this->_name << " couldn't sign " << form.getName() << " because grade is too low" << std::endl;
}