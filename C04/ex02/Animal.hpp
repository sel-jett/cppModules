/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:52:19 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/21 09:29:33 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal {
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal& obj);
        Animal& operator=(const Animal& obj);
        virtual ~Animal();
        Animal(const std::string& type);
        std::string getType( void ) const;
        virtual void makeSound() const = 0;
    
};