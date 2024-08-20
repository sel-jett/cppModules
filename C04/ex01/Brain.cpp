/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:46:54 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/20 08:56:13 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;    
    for (int i = 0; i < 100; ++i) {
        ideas[i] = "default idea";  // You can choose any default value here
    }
}

Brain::Brain(const Brain& obj)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        ideas[i] = obj.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& obj)
{
    if (this != &obj)
    {
        for (int i = 0; i < 100; i++)
        {
            ideas[i] = obj.ideas[i];
        }
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
}