/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:05:02 by ochoumou          #+#    #+#             */
/*   Updated: 2022/11/08 15:21:51 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberCreationForm.hpp"


int main(void)
{
    // We will need a main here also to verify weather these exercise is working or not.
    // First try to create an instant of form to prove that the class is abstract.
    Bureaucrat bureau("Chrif", 5);
    PresidentialPardonForm pardon("bosama");
    ShrubberCreationForm jarda("chowafa");
    bureau.signForm(jarda);
    bureau.executeForm(jarda);
    bureau.signForm(pardon);
    bureau.executeForm(pardon);
}
