#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook book;

    int i;

    i = 0;

    book.length = 0;
    book.contact_add();
    book.contact_add();
    book.contact_add();
    book.search_contact();
    return (0);
}