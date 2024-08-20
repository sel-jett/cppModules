/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:05:21 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/20 14:07:33 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class Cure: public AMateria {
    public:
        Cure();
        Cure(const Cure& obj);
        Cure& operator=(const Cure& obj);
        ~Cure();
        void use(ICharacter&) const;
};