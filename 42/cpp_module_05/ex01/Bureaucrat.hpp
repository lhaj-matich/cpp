#ifndef BUREAUCRAT_H_
#define BUREAUCRAT_H_

#include <iostream>
#include "Form.hpp"

class Bureaucrat 
{
    public:
        int     getGrade(void);
        void    signForm(Form &from);
    private:
        const std::string _name;
        int _grade;
};

#endif