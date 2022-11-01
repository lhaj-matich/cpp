#ifndef _BUREAUCRAT_H_
#define _BUREAUCRAT_H_

#include <iostream>
#include <exception>

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
        std::string getName(void);
        int getGrade(void);

    private:
        const std::string _name;
        int _grade;
};

std::ostream & operator<<(std::ostream & output, Bureaucrat & input);

#endif