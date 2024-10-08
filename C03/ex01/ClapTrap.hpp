/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 02:50:36 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/18 06:22:36 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap{
  
  protected:
    std::string Name;
    int         hit_points;
    int         energy_points;
    int         attack_damage;
  
  public:
    ClapTrap();
    ClapTrap(const ClapTrap& obj);
    ClapTrap& operator=(const ClapTrap& obj);
    ~ClapTrap();
    ClapTrap(std::string Name);
    std::string getName( void ) const;
    int getHitPoints( void ) const;
    int getEnergyPoints( void ) const;
    int getAttackPoints( void ) const;
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    
};