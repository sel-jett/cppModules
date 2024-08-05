/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:30:20 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/05 22:32:43 by sel-jett         ###   ########.fr       */
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
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};

	choice = (level == "DEBUG") * 1 + (level == "INFO") * 2 + (level == "WARNING") * 3 + (level == "ERROR") * 4 - 1;
	switch(choice)
	{
		case (-1):
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
		case (0):
			(this->*functionArray[choice])();
			(this->*functionArray[choice + 1])();
			(this->*functionArray[choice + 2])();
			(this->*functionArray[choice + 3])();
			break ;
		case (1):
			(this->*functionArray[choice])();
			(this->*functionArray[choice + 1])();
			(this->*functionArray[choice + 2])();
			break ;
		case (2):
			(this->*functionArray[choice])();
			(this->*functionArray[choice + 1])();
			break ;
		case (3):
			(this->*functionArray[choice])();
			break ;
	}
}
