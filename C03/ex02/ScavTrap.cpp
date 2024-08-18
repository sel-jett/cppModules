/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 22:55:06 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/18 07:02:55 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap():_guardGate(false)
{
    std::cout << "ScavTrap Default constructor called" << std::endl;
    this->Name = "Unkown";
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
}


ScavTrap::ScavTrap(std::string Name):_guardGate(false)
{
    std::cout << "ScavTrap Modified constructor called" << std::endl;
    this->Name = Name;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;    
}

ScavTrap::ScavTrap(const ScavTrap& obj)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = obj;
}

bool ScavTrap::getGuardGate() const
{
    return (this->_guardGate);    
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
    if (this != &obj)
    {
        Name = obj.getName();
        _guardGate = obj.getGuardGate();
        hit_points = obj.getHitPoints();
        energy_points = obj.getEnergyPoints();
        attack_damage = obj.getAttackPoints();
    }
    return (*this);
}

void ScavTrap::guardGate()
{
    _guardGate = true;
    std::cout << "\033[34mScavTrap is now on Gate keeper mode\033[0m" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (energy_points > 0 && hit_points > 0)
    {
        --energy_points;
        std::cout << "ScavTrap " << Name << " attacks " << target << " , causing " << attack_damage << " points of damage!" << std::endl;
    }
    else if (hit_points > 0)
        std::cout << "ScavTrap Can't attack" << std::endl;
    else
        std::cout << "ScaveTrap " << Name << " is already dead! 😔" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (_guardGate && hit_points > 0 && energy_points > 0)
    {
        std::cout << "ScaveTrap " << Name << " is on GuardMode" << std::endl;
        return ;
    }
    if (hit_points > 0 && (unsigned int)hit_points <= amount)
    {
        hit_points = 0;
        std::cout << "ScaveTrap " << Name << " takeDamage , having " << amount << " points of damage!" << std::endl;
        std::cout << "\033[31mScaveTrap " << Name << " losed! 💔\033[0m" << std::endl;
    }
    else if (hit_points > 0)
    {
        hit_points -= amount;
        std::cout << "ScaveTrap " << Name << " takeDamage , having " << amount << " points of damage!" << std::endl;
    }
    else
        std::cout << "ScaveTrap " << Name << " is already dead! 😔" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (energy_points > 0)
    {
        --energy_points;
        std::cout << "\033[32mScaveTrap " << Name << " is Repaired 🔋, losing " << amount << " energy points!\033[0m" << std::endl;
    }
    else
        std::cout << "ScaveTrap " << Name << " has no energy points left" << std::endl;
}