#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"


std::string get_command(void)
{
    std::string cmd;

    std::cout << "Enter your command: ";
    getline(std::cin, cmd);
    if (std::cin.eof())
        return (cmd);
    return (cmd);
}

int main(void)
{
    std::string command;
    PhoneBook book;

    book.length = 0;
    command = get_command();
    while (!command.empty())
    {
        if (!strcmp(command.c_str(), "EXIT"))
            exit(1);
        else if (!strcmp(command.c_str(), "SEARCH"))
            book.search_contact();
        else if (!strcmp(command.c_str(), "ADD"))
            book.contact_add();
        command = get_command();
    }
    return (0);
}

