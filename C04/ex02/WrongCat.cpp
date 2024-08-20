/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 05:43:51 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/19 05:50:29 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
    std::cout << "WrongCat Default Constructor Called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj)
{
    std::cout << "WrongCat Copy Constructor called" << std::endl;
    *this = obj;
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
    if (this != &obj)
        type = obj.type;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat !! ghost doesn't make sounds 👻" << std::endl;
}