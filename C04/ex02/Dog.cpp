/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 04:42:01 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/20 09:02:37 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog"), brain(new Brain())
{
    std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::Dog(const Dog& obj): Animal(obj)
{
    std::cout << "Dog Copy Constructor called" << std::endl;
    if (obj.brain)
        brain = new Brain(*obj.brain);
    else
        brain = NULL;
}

Dog& Dog::operator=(const Dog& obj)
{
    if (this != &obj)
    {
        delete brain;
        type = obj.type;
        brain = new Brain(*obj.brain);
    }
    return (*this);
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "hoooow 🐶" << std::endl;
}