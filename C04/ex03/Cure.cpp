/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:15:32 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/20 15:49:06 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cure.hpp"

Cure::Cure():AMateria("cure")
{
    std::cout << "Cure Default Constructor called" << std::endl;
}

Cure::Cure(const Cure& obj):AMateria("cure")
{
    std::cout << "Cure Copy Constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& obj)
{
    if (this != &obj)
    {
        type = obj.type;
    }
    return *this;
}

Cure::~Cure()
{
    std::cout << "Destructor Called" << std::endl;
}