/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:02:04 by ochoumou          #+#    #+#             */
/*   Updated: 2022/10/10 15:02:05 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H_
#define CONTACT_H_
#include <iostream>


class Contact 
{
    private:
        int index;
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string phone_number;
        std::string dark_secret;
    public:
        std::string get_firstname(bool trunck);
        std::string get_lastname(bool trunck);
        std::string get_phonenumber(bool trunck);
        std::string get_secret(bool trunck);
        std::string get_nickname(bool trunck);
        int    set_contact(int index);
};

#endif