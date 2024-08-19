/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 04:40:02 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/19 05:17:49 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog: public Animal {
    public:
        Dog();
        Dog(const Dog& obj);
        Dog& operator=(const Dog &obj);
        ~Dog();
        void makeSound() const;
};