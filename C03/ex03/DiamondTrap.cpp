/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:42:44 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/18 13:27:20 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

DiamondTrap::DiamondTrap():ClapTrap("Default_clap_name")
{
    std::cout << "Diamond Default Constructor Called" << std::endl;
    Name = "Default";
    hit_points = FragTrap::hit_points;
    energy_points = ScavTrap::energy_points;
    attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj)
{
    std::cout << "Diamond Copy Constructor Called" << std::endl;
    *this = obj;
}

DiamondTrap::DiamondTrap(std::string name):ClapTrap(name + "_clap_name")
{
    std::cout << "Diamond Default Constructor Called" << std::endl;
    Name = name;
    hit_points = FragTrap::hit_points;
    energy_points = ScavTrap::energy_points;
    attack_damage = FragTrap::attack_damage;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
    if (this != &obj)
    {
        Name = obj.Name;
        ClapTrap::Name = obj.Name + "_clap_name";
        hit_points = obj.hit_points;
        energy_points = obj.energy_points;
        attack_damage = obj.attack_damage;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Diamond Destructor Called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "Diamond Name : " << Name << std::endl;
    std::cout << "ClapTrap Name : " << ClapTrap::Name << std::endl;
}

