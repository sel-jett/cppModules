/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 04:40:02 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/20 08:08:42 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
    private:
        Brain* brain;
    public:
        Dog();
        Dog(const Dog& obj);
        Dog& operator=(const Dog &obj);
        ~Dog();
        void makeSound() const;
};