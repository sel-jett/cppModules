/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 04:35:11 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/20 08:34:35 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
    private:
        Brain* brain;
    public:
        Cat();
        Cat(const Cat& obj);
        Cat& operator=(const Cat &obj);
        ~Cat();
        void makeSound() const;
        const std::string* getBrainIdeas( void ) const;
        
};