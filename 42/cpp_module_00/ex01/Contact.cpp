#include "Contact.hpp"

std::string Contact::get_firstname(bool trunck)
{
    if (trunck)
        return this->firstname.length() >= 10 ? this->firstname.substr(0, 9).append(".") : this->firstname;
    return (this->firstname);
}

std::string Contact::get_lastname(bool trunck)
{
    if (trunck)
        return this->lastname.length() >= 10 ? this->lastname.substr(0, 9).append(".") : this->lastname;
    return (this->lastname);
}

std::string Contact::get_nickname(bool trunck)
{
    if (trunck)
        return this->nickname.length() >= 10 ? this->nickname.substr(0, 9).append(".") : this->nickname;
    return (this->nickname);
}

std::string Contact::get_secret(bool trunck)
{
    if (trunck)
        return this->dark_secret.length() >= 10 ? this->dark_secret.substr(0, 9).append(".") : this->dark_secret;
    return (this->dark_secret);
}

std::string Contact::get_phonenumber(bool trunck)
{
    if (trunck)
        return this->phone_number.length() >= 10 ? this->phone_number.substr(0, 9).append(".") : this->phone_number;
    return (this->phone_number);
}

int    Contact::set_contact(int index)
{
    this->index = index;
    std::cout << "Enter your firstname: ";
    getline(std::cin, this->firstname);
    std::cout << "Enter your lastname: ";
    getline(std::cin, this->lastname);
    // std::cout << "Enter your nickname: ";
    // getline(std::cin, this->nickname);
    // std::cout << "Enter your phone number: ";
    // getline(std::cin, this->phone_number);
    // std::cout << "Enter your darkest secret: ";
    // getline(std::cin, this->dark_secret);
    if (this->firstname.empty() || this->lastname.empty())
        return 0;
    return (1);
}

//  || this->nickname.empty() || this->phone_number.empty() || this->dark_secret.empty()