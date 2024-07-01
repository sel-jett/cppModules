/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:32:49 by sel-jett          #+#    #+#             */
/*   Updated: 2024/07/01 18:56:36 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->type = type;
}

Weapon::~Weapon()
{
    std::cout << "Weapon destroyed" << std::endl;
}

std::string const &Weapon::getType()
{
    return (this->type);
}

void &Weapon::setType(std::string type)
{
    this->type = type;
}

