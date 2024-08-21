/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 01:29:43 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/21 06:15:13 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): Name("Default Character")
{
    // std::cout << "Character Default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        slots[i] = NULL;
    }
}

Character::Character(const Character& obj)
{
    // std::cout << "Character Copy constructor called" << std::endl;
    *this = obj;
}

Character::Character(const std::string& Name): Name(Name)
{
    // std::cout << "Character Parametrize constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        slots[i] = NULL;
    }
}

Character& Character::operator=(const Character& obj)
{
    if (this != &obj)
    {
        Name = obj.getName();
        for (int i = 0; i < 4; i++)
        {
            if (this->slots[i])
                delete this->slots[i];
            this->slots[i] = obj.slots[i]->clone();
        }
    }
    return (*this);
}

Character::~Character()
{
    // std::cout << "Character Destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        delete this->slots[i];
    }
}

const std::string& Character::getName( void ) const
{
    return (this->Name);
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->slots[i] == NULL)
            break;
        else if (i == 3)
            return ;
    }
    for (int i = 0; i < 4; i++)
    {
        if (this->slots[i] == m)
            return ;
    }
    for (int i = 0; i < 4; i++)
    {
        if (this->slots[i] == NULL)
        {
            this->slots[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        this->slots[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4)
        if (this->slots[idx])
            this->slots[idx]->use(target);
}




