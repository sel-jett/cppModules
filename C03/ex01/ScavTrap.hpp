/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 21:35:21 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/18 06:39:18 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap{
    private:
        bool _guardGate;
    public:
        ScavTrap();
        ScavTrap(std::string Name);
        ScavTrap(const ScavTrap& obj);
        ScavTrap& operator=(const ScavTrap& obj);
        ~ScavTrap();
        bool getGuardGate() const;
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void guardGate();
};