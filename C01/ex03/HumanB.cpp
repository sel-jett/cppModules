/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:38:34 by sel-jett          #+#    #+#             */
/*   Updated: 2024/07/05 10:20:16 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->weapon = NULL;
}

HumanB::~HumanB()
{
    // std::cout << "HumanB " << this->name << "Being destructed" << std::endl;
}

void HumanB::attack()
{
    if (this->weapon == NULL)
        std::cout << this->name << " has no weapon !!!" << std::endl;
    else
        std::cout << this->name << "attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;   
}