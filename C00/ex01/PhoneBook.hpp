/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:54:06 by sel-jett          #+#    #+#             */
/*   Updated: 2024/07/03 22:05:07 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int     nb_contacts;
        
    public:
        PhoneBook();
        
        void display_contact();
        void add_contact();
        void search_contact(long long index);
        
        ~PhoneBook();
};

#endif