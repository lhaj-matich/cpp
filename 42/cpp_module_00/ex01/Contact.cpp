/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:02:01 by ochoumou          #+#    #+#             */
/*   Updated: 2022/10/10 15:02:02 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::get_firstname(bool trunck)
{
    int length;

    length = this->firstname.length();
    if (trunck)
        return length >= 9 ? this->firstname.substr(0, 9).append(".") : this->firstname;
    return (this->firstname);
}

std::string Contact::get_lastname(bool trunck)
{
    int length;

    length = this->lastname.length();
    if (trunck)
        return length >= 9 ? this->lastname.substr(0, 9).append(".") : this->lastname;
    return (this->lastname);
}

std::string Contact::get_nickname(bool trunck)
{
    int length;

    length = this->nickname.length();
    if (trunck)
        return length >= 9 ? this->nickname.substr(0, 9).append(".") : this->nickname;
    return (this->nickname);
}

std::string Contact::get_secret(bool trunck)
{
   int length;

    length = this->dark_secret.length();
    if (trunck)
        return length >= 9 ? this->dark_secret.substr(0, 9).append(".") : this->dark_secret;
    return (this->dark_secret);
}

std::string Contact::get_phonenumber(bool trunck)
{
    int length;

    length = this->phone_number.length();
    if (trunck)
        return length >= 9 ? this->phone_number.substr(0, 9).append(".") : this->phone_number;
    return (this->phone_number);
}

int    Contact::set_contact(int index)
{
    this->index = index;
    std::cout << "Enter your firstname: ";
    getline(std::cin, this->firstname);
    if (this->firstname.empty())
        exit(1);
    std::cout << "Enter your lastname: ";
    getline(std::cin, this->lastname);
    if (this->lastname.empty())
        exit(1);
    std::cout << "Enter your nickname: ";
    getline(std::cin, this->nickname);
    if (this->nickname.empty())
        exit(1);
    std::cout << "Enter your phone number: ";
    getline(std::cin, this->phone_number);
    if (this->phone_number.empty())
        exit(1);
    std::cout << "Enter your darkest secret: ";
    getline(std::cin, this->dark_secret);
    if (this->dark_secret.empty())
        exit(1);
    return (1);
}