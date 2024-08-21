/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 23:35:27 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/21 02:49:17 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(): type("Default")
{
}

AMateria::AMateria(std::string const & type): type(type)
{
   std::cout << "AMateria Parametrize constructor" << std::endl;
}

AMateria::AMateria(const AMateria &obj)
{
    std::cout << "AMateria copy constructor" << std::endl;
    *this = obj;
}

AMateria& AMateria::operator=(const AMateria &obj)
{
    if (this != &obj)
        this->type = obj.type;
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << "AMateria Destructor called" << std::endl;
}

std::string const& AMateria::getType() const
{
    return (this->type);
}

AMateria* AMateria::clone() const
{
    return (AMateria *)this;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}
