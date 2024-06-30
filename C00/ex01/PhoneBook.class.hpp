/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:54:06 by sel-jett          #+#    #+#             */
/*   Updated: 2024/06/30 17:52:49 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#include "Contact.class.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int     nb_contacts;
        const   a = 8;
        
    public:
        PhoneBook();
        
        void add_contact();
        void search_contact(long long index);
        
        ~PhoneBook();
};

#endif