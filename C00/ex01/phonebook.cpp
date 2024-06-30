/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:44:48 by sel-jett          #+#    #+#             */
/*   Updated: 2024/06/30 18:17:10 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

#include <iomanip>
#include <iostream>

Contact::Contact()
{
    this->first_name = "";
    this->last_name = "";
    this->nickname = "";
    this->phone_number = "";
    this->darkest_secret = "";
}

Contact::~Contact()
{
    std::cout << "Contact destroyed" << std::endl;   
}

PhoneBook::PhoneBook()
{
    this->nb_contacts = 0;
}

PhoneBook::~PhoneBook()
{
    std::cout << "PhoneBook destroyed" << std::endl;
}

void   Contact::set_first_name(std::string first_name)
{
    this->first_name = first_name;
}

void   Contact::set_last_name(std::string last_name)
{
    this->last_name = last_name;
}

void   Contact::set_nickname(std::string nickname)
{
    this->nickname = nickname;
}

void   Contact::set_phone_number(std::string phone_number)
{
    this->phone_number = phone_number;
}

void   Contact::set_darkest_secret(std::string darkest_secret)
{
    this->darkest_secret = darkest_secret;
}

std::string   Contact::get_first_name()
{
    std::string str;
    
    str = this->first_name;
    return str;
}

std::string   Contact::get_last_name()
{
    std::string str;
    
    str = this->last_name;
    return str;
}

std::string   Contact::get_nickname()
{
    std::string str;
    
    str = this->nickname;
    return str;
}


void   PhoneBook::add_contact()
{
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
    
    if (this->nb_contacts == 8)
    {
        this->nb_contacts = 0;
    }
    
    while (first_name.empty())
    {
        std::cout << "Enter first name: ";
        std::getline(std::cin, first_name);
        if (std::cin.eof())
            return ;
    }

    while (last_name.empty())
    {
        std::cout << "Enter last name: ";
        std::getline(std::cin, last_name);
        if (std::cin.eof())
            return ;
    }
    
    while (nickname.empty())
    {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, nickname);
        if (std::cin.eof())
            return ;
    }

    while (phone_number.empty())
    {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, phone_number);
        if (std::cin.eof())
            return ;
    }

    while (darkest_secret.empty())
    {
        std::cout << "Enter darkest secret: ";
        std::getline(std::cin, darkest_secret);
        if (std::cin.eof())
            return ;
    }
    this->contacts[this->nb_contacts].set_first_name(first_name);
    this->contacts[this->nb_contacts].set_last_name(last_name);
    this->contacts[this->nb_contacts].set_nickname(nickname);
    this->contacts[this->nb_contacts].set_phone_number(phone_number);
    this->contacts[this->nb_contacts].set_darkest_secret(darkest_secret);
    this->nb_contacts++;

    std::cout << "Contact added successfully!" << std::endl;
}


std::string display_str(std::string str)
{
    if (str.length() > 10)
    {
        str.resize(9);
        str.append(".");
    }
    return str;
}

void PhoneBook::search_contact(long long index)
{
    if (index < 0 || index > 7)
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    else if (this->contacts[index].get_first_name().empty())
    {
        std::cout << "Contact not found" << std::endl;
        return;
    }
    std::cout << "     Index|First name| Last name|  Nickname" << std::endl;
    std::cout << std::setw(10);
    std::cout << index ;
    std::cout << "|"; 
    std::cout << std::setw(10);
    std::cout << display_str(this->contacts[index].get_first_name()); 
    std::cout << "|";
    std::cout << std::setw(10);
    std::cout << display_str(this->contacts[index].get_last_name());
    std::cout << "|";
    std::cout << std::setw(10);
    std::cout << display_str(this->contacts[index].get_nickname());
    std::cout << std::endl;
}

int main(void)
{
    PhoneBook   phonebook;
    std::string command;
    std::string index;
    long long   index_int;
    
    while(1)
    {
        std::cout << "Enter a command: ";
        std::getline(std::cin, command);
        if (std::cin.eof())
            break;
        if (command == "EXIT")
            break;
        else if (command == "ADD")
        {   
            command.clear();
            phonebook.add_contact();
        }
        else if (command == "SEARCH")
        {
            command.clear();
            std::cout << "Enter index: ";
            std::cin >> index;
            index_int = std::atoi(index.c_str());
            if (index_int > std::numeric_limits<long>::max())
            {
                std::cout << "Invalid index" << std::endl;
                continue;
            }
            phonebook.search_contact(index_int);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return 0;
}