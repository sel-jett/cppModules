/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 04:31:11 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/19 11:36:19 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("Animal")
{
    std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(const Animal& obj)
{
    std::cout << "Animal Copy Constructor called" << std::endl;
    *this = obj;
}

Animal::Animal(const std::string& type): type(type){
    std::cout << "Animal Default Constructor called" << std::endl;
} 

Animal& Animal::operator=(const Animal& obj)
{
    if (this != &obj)
        type = obj.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

std::string Animal::getType( void ) const
{
    return (this->type);
}

void Animal::makeSound() const {
    std::cout << "Anonimous Animal" << std::endl;
}