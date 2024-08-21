/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 23:51:34 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/21 06:14:16 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ICharacter.hpp"

class Character: public ICharacter {
    private:
        std::string Name;
        AMateria *slots[4];
    public:
        Character();
        Character(const Character& obj);
        Character(const std::string& Name);
        Character& operator=(const Character& obj);
        ~Character();
        const std::string& getName( void ) const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
      
};