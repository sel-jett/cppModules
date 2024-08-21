/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:15:32 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/21 05:35:56 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure():AMateria("cure")
{
    std::cout << "Cure Default Constructor called" << std::endl;
}

Cure::Cure(const Cure& obj)
{
    std::cout << "Cure Copy Constructor called" << std::endl;
    *this = obj;
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

AMateria* Cure::clone() const 
{
    return (new Cure());
}

void Cure::use(ICharacter& C)
{
    std::cout << "* heals " << C.getName() << "’s wounds *" << std::endl;
}