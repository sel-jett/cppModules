/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:30:20 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/05 21:55:36 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl's Contructed is called !!" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl's Destructer is called !!" << std::endl;
}
void Harl::debug()
{
	std::cout << "[ DEBUG ]\n "<< " love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "[ INFO ]\n "<< "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "[ WARNING ]\n "<< " think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
	std::cout << "[ ERROR ]\n "<< "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
	typedef void (Harl::*MemberFunctionPtr)();
    int choice;

    MemberFunctionPtr functionArray[4] = {
		&Harl::error,
		&Harl::warning,
		&Harl::info,
		&Harl::debug,
	};

	choice = (level == "ERROR") * 1 + (level == "WARNING") * 2 + (level == "INFO") * 3 + (level == "DEBUG") * 4 - 1;
	if (choice == -1)
	{
		std::cout << level << " doesn't exist :(" << std::endl;
		return ;
	}
	(this->*functionArray[choice])();
}
