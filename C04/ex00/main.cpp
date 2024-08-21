/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 04:48:07 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/21 09:20:04 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const WrongCat* notCat = new WrongCat();
    const WrongAnimal* notAnimal = new WrongAnimal();
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << "type => " << j->getType() << std::endl;
    std::cout << "type => " << i->getType() << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    notCat->makeSound();
    notAnimal->makeSound();
    delete notCat;
    delete notAnimal;
    delete j;
    delete i;
    delete meta;
    return 0;
}