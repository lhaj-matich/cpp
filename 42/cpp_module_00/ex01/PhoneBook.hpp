#ifndef PHONEBOOK_H_
#define PHONEBOOK_H_

#include "Contact.hpp"

class PhoneBook {
    private:
        Contact contacts[8];
    public:
        int     length;
        void    contact_add();
        void    contact_display(int);
        void    search_contact(void);
  
};

void    PhoneBook::search_contact()
{
    int i;
    std::string index;
    std::string contact;

    i = 0;
    while (i < this->length)
    {
       std::cout << i << " " << this->contacts[i].get_firstname(true).append("|").append(this->contacts[i].get_lastname(true)).append("|") << std::endl;
        i++;
    }
    std::cout << "Enter the contact index: ";
    getline(std::cin, index);
    this->contact_display(atoi(index.c_str()));
}

void    PhoneBook::contact_display(int index)
{
    if (index > 7 || index < 0)
        std::cout << "Incorrect contact index." << std::endl;
    std::cout << "Firstname: " << this->contacts[index].get_firstname(false) << std::endl;
    std::cout << "Lastname: " << this->contacts[index].get_lastname(true) << std::endl;
    // std::cout << "Nickname : " << this->contacts[index].get_nickname(true) << std::endl;
//     std::cout << "Phone number:  " << this->contacts[index].get_phonenumber(false) << std::endl;
//     std::cout << "Darkest secret: " << this->contacts[index].get_secret(false) << std::endl;
}

void    PhoneBook::contact_add()
{
    static int i;
    
    if (i >= 7)
        i = 0;
    this->contacts[i].set_contact(i);
    this->length += 1;
    i += 1;
}

#endif