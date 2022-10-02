#ifndef PHONEBOOK_H_
#define PHONEBOOK_H_

#include "Contact.hpp"
#include <iomanip> 

class PhoneBook {
    private:
        Contact contacts[8];
    public:
        int     length;
        void    contact_add();
        void    contact_display(int);
        void    search_contact(void);
  
}; 

void    display_columns(int, std::string, std::string , std::string);

#endif