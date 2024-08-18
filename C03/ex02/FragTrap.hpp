/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 07:40:11 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/18 07:59:53 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
    public:
        FragTrap();
        FragTrap(const FragTrap& obj);
        FragTrap(std::string Name);
        FragTrap& operator=(const FragTrap& obj);
        ~FragTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void highFivesGuys(void);
        
};