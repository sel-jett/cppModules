/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 03:59:25 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/21 04:46:58 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource Default constructor" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        materia[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
    std::cout << "MateriaSource Copy constructor called" << std::endl;
    *this = obj;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
    if (this != &obj)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->materia[i])
                delete this->materia[i];
            this->materia[i] = obj.materia[i]->clone();
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource Default Destructor" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (materia[i])
            delete materia[i];
    }
}

void MateriaSource::learnMateria(AMateria* mtr)
{
    for (int i = 0; i < 4; i++)
    {
        if (!this->materia[i] && mtr)
        {
            this->materia[i] = mtr->clone();
            return ;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->materia[i]->getType() == type)
        {
            return (this->materia[i]->clone());
        }
    }
    return (0);
}