/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 02:52:21 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/21 04:10:00 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
    private :
        AMateria *materia[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &obj);
        MateriaSource& operator=(const MateriaSource &obj);
        ~MateriaSource();
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const &);
};