/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 04:40:23 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/19 05:51:52 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
    std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::Cat(const Cat& obj)
{
    std::cout << "Cat Copy Constructor called" << std::endl;
    *this = obj;
}

Cat& Cat::operator=(const Cat& obj)
{
    if (this != &obj)
        type = obj.type;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "meow 🐈" << std::endl;
}