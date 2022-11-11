/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:04:58 by ochoumou          #+#    #+#             */
/*   Updated: 2022/11/11 18:59:49 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

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
		void	beSigned(Bureaucrat const & bureaucrat);
		void	execute(Bureaucrat const & executor) const;
		virtual void	procedure() const = 0;
	private:
		const	std::string _name;
		const	int _sign_grade;
		const	int _exec_grade;
		bool _is_signed;
};

std::ostream & operator<<(std::ostream & output, const Form & input);

#endif