/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 04:42:01 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/19 05:18:40 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
    std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::Dog(const Dog& obj)
{
    std::cout << "Dog Copy Constructor called" << std::endl;
    *this = obj;
}

Dog& Dog::operator=(const Dog& obj)
{
    if (this != &obj)
        type = obj.type;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "hoooow 🐶" << std::endl;
}