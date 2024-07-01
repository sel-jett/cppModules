/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:33:48 by sel-jett          #+#    #+#             */
/*   Updated: 2024/07/01 18:53:50 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon)
{
    this->name = name;
    this->weapon = &weapon;
}

HumanA::~HumanA()
{
    std::cout << "HumanA being destructed" << std::endl;
}

void HumanA::attack()
{
    std::cout << this->name << "attacks with their " << this->weapon->getType() << std::endl;
}