/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 06:25:34 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/18 06:52:30 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():Name("Unkown"), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = obj;
}

ClapTrap::ClapTrap(std::string Name):Name(Name), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap overloaded Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" << std::endl;    
}

int ClapTrap::getHitPoints( void ) const
{
    return (this->hit_points);
}

int ClapTrap::getEnergyPoints( void ) const
{
    return (this->energy_points);
}

int ClapTrap::getAttackPoints( void ) const
{
    return (this->attack_damage);
}

std::string ClapTrap::getName( void ) const
{
    return (this->Name);
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
    if (this != &obj)
    {
        Name = obj.getName();
        hit_points = obj.getHitPoints();
        energy_points = obj.getEnergyPoints();
        attack_damage = obj.getAttackPoints();
    }
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (energy_points > 0 && hit_points > 0)
    {
        --energy_points;
        std::cout << "ClapTrap " << Name << " attacks " << target << "👿 , causing " << attack_damage << " points of damage!" << std::endl;
    }
    else if (hit_points > 0)
        std::cout << "ClapTrap Can't attack" << std::endl;
    else
        std::cout << "ClapTrap " << Name << " is already dead!" << std::endl;
        
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hit_points > 0 && (unsigned int)hit_points <= amount)
    {
        hit_points = 0;
        std::cout << "ClapTrap " << Name << " takeDamage , having " << amount << " points of damage!" << std::endl;
        std::cout << "You've losed! 💔" << std::endl;
    }
    else if (hit_points > 0)
    {
        hit_points -= amount;
        std::cout << "ClapTrap " << Name << " takeDamage , having " << amount << " points of damage!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << Name << " is already dead!" << std::endl;
    
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energy_points != 0)
    {
        --energy_points;
        std::cout << "ClapTrap " << Name << " is Repaired , losing 🔋" << amount << " energy poin!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << Name << " has no energy points left" << std::endl;
}
