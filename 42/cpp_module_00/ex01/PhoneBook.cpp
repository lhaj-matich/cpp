/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:13:50 by ochoumou          #+#    #+#             */
/*   Updated: 2022/10/02 20:19:03 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void    PhoneBook::search_contact()
{
    int i;
    std::string index;

    i = 0;
    while (i < this->length && i < 8)
    {
        display_columns(i ,this->contacts[i].get_firstname(true), \
        this->contacts[i].get_lastname(true), this->contacts[i].get_nickname(true));
        i++;
    }
    std::cout << "Enter the contact index: ";
    getline(std::cin, index);
    if (index.empty())
        return ;
    this->contact_display(atoi(index.c_str()));
}

void    PhoneBook::contact_display(int index)
{
    if ((index > 8 || index > this->length) || index <= 0)
    {
        std::cout << "Incorrect contact index." << std::endl;
        return ;
    }
    std::cout << "Firstname: " << this->contacts[index - 1].get_firstname(false) << std::endl;
    std::cout << "Lastname: " << this->contacts[index - 1].get_lastname(false) << std::endl;
    std::cout << "Nickname : " << this->contacts[index - 1].get_nickname(false) << std::endl;
    std::cout << "Phone number:  " << this->contacts[index - 1].get_phonenumber(false) << std::endl;
    std::cout << "Darkest secret: " << this->contacts[index - 1].get_secret(false) << std::endl;
}

void    PhoneBook::contact_add()
{
    if (this->contacts[this->length % 8].set_contact(this->length % 8))
        this->length += 1;
}

void    display_columns(int index, std::string firstname, std::string lastname, std::string nickname)
{
    std::cout << "|";
    std::cout << std::setw(10) << index + 1;
    std::cout << "|";
    std::cout << std::setw(10) << firstname;
    std::cout << "|";
    std::cout << std::setw(10) << lastname;
    std::cout << "|";
    std::cout << std::setw(10) << nickname;
    std::cout << "|";
    std::cout << std::endl;
}