/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:05:09 by ochoumou          #+#    #+#             */
/*   Updated: 2022/11/09 13:36:58 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public:
		// Constructors
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm(std::string target);
		
		// Destructor
		virtual ~PresidentialPardonForm();
		
		// Operators
		PresidentialPardonForm & operator=(const PresidentialPardonForm &assign);
		
		// Member function

		void	procedure() const;
		
	private:
		std::string _target;
		
};

#endif