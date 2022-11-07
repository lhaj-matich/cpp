/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:04:53 by ochoumou          #+#    #+#             */
/*   Updated: 2022/11/07 12:00:10 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H_
#define BUREAUCRAT_H_

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat 
{
    public:
        // Constructors and destructor
        Bureaucrat();
        Bureaucrat(std::string, int);
        Bureaucrat(Bureaucrat const & copy);
        ~Bureaucrat();

        // Overload the copy assigment operator
        Bureaucrat & operator=(Bureaucrat const & assign);

        // Exceptions
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };

        class GradeTooHighException: public std::exception
        {
            public:
                const char *what() const throw();
        };
        // Member functions
        void    incrementGrade(void);
        void    decrementGrade(void);

        std::string getName(void) const;
        int     getGrade(void) const;

        void    signForm(Form &from);
        void    executeForm(Form const & form);
        
    private:
        const std::string _name;
        int _grade;
};

std::ostream & operator<<(std::ostream & output, Bureaucrat & input);

#endif