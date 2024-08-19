/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 04:35:11 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/19 05:16:39 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat: public Animal {
    public:
        Cat();
        Cat(const Cat& obj);
        Cat& operator=(const Cat &obj);
        ~Cat();
        void makeSound() const;
};