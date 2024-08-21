/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:08:26 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/21 05:36:26 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
    std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice& obj): AMateria("ice")
{
    std::cout << "Ice copy constructor called" << std::endl;
    *this = obj;
}

Ice& Ice::operator=(const Ice& obj)
{
    if (this != &obj)
    {
        type = obj.type;
    }
    return *this;
}

Ice::~Ice()
{
    std::cout << "Ice Destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
    return (new Ice());
}

void Ice::use(ICharacter& C)
{
    std::cout << "* shoots an ice bolt at " << C.getName() << std::endl;
}
