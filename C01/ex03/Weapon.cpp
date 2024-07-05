/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:32:49 by sel-jett          #+#    #+#             */
/*   Updated: 2024/07/05 10:16:32 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type): type(type)
{
    // this->type = type;
}

Weapon::~Weapon()
{
}

std::string const Weapon::getType() const
{
    return type;
}

void Weapon::setType(const std::string &type_str)
{
    type = type_str;
}

