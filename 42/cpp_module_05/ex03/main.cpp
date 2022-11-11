/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:05:02 by ochoumou          #+#    #+#             */
/*   Updated: 2022/11/11 13:51:02 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberCreationForm.hpp"
#include "Intern.hpp"


int main(void)
{
    // Here i'll need a main function that will test out the intern class implementation.
    Bureaucrat sector("Lhaj", 30);
    Intern sami;
    Form *form;
    try 
    {
        form = sami.makeForm("RobotomyRequestForm", "Khadija");
        sector.signForm(*form);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
