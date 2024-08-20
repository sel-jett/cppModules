/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 04:40:23 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/20 09:00:17 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Cat"), brain(new Brain())
{
    std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::Cat(const Cat& obj): Animal(obj)
{
    std::cout << "Cat Copy Constructor called" << std::endl;
    if (obj.brain)
        brain = new Brain(*obj.brain);
    else
        brain = NULL;
}

Cat& Cat::operator=(const Cat& obj)
{
    if (this != &obj)
    {
        delete brain;
        type = obj.type;
        brain = new Brain(*obj.brain);
    }
    return (*this);
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "meow 🐈" << std::endl;
}