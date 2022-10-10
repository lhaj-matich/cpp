/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:02:49 by ochoumou          #+#    #+#             */
/*   Updated: 2022/10/10 15:02:50 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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