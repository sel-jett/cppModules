/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 05:40:54 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/19 05:53:27 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
    std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
    std::cout << "WrongAnimal Copy Constructor called" << std::endl;
    *this = obj;
}

WrongAnimal::WrongAnimal(const std::string& type): type(type){} 

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
    if (this != &obj)
        type = obj.type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

std::string WrongAnimal::getType( void ) const
{
    return (this->type);
}

void WrongAnimal::makeSound() const {
    std::cout << "Anonimous WrongAnimal" << std::endl;
}