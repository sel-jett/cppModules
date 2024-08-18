/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 07:50:12 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/18 13:35:25 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap Default constructor called" << std::endl;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
}

FragTrap::FragTrap(std::string Name)
{
    std::cout << "FragTrap Modified constructor called" << std::endl;
    this->Name = Name;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;    
}

FragTrap::FragTrap(const FragTrap& obj)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = obj;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
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

void FragTrap::attack(const std::string& target)
{
    if (energy_points > 0 && hit_points > 0)
    {
        --energy_points;
        std::cout << "FragTrap " << Name << " attacks " << target << " , causing " << attack_damage << " points of damage!" << std::endl;
    }
    else if (hit_points > 0)
        std::cout << "FragTrap Can't attack" << std::endl;
    else
        std::cout << "FragTrap " << Name << " is already dead! 😔" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
    if (hit_points > 0 && (unsigned int)hit_points <= amount)
    {
        hit_points = 0;
        std::cout << "FragTrap " << Name << " takeDamage , having " << amount << " points of damage!" << std::endl;
        std::cout << "\033[31mFragTrap " << Name << " losed! 💔\033[0m" << std::endl;
    }
    else if (hit_points > 0)
    {
        hit_points -= amount;
        std::cout << "FragTrap " << Name << " takeDamage , having " << amount << " points of damage!" << std::endl;
    }
    else
        std::cout << "FragTrap " << Name << " is already dead! 😔" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
    if (energy_points > 0)
    {
        --energy_points;
        std::cout << "\033[32mFragTrap " << Name << " is Repaired 🔋, losing " << amount << " energy points!\033[0m" << std::endl;
    }
    else
        std::cout << "FragTrap " << Name << " has no energy points left" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "Positive high five request! ✋" << std::endl;
}