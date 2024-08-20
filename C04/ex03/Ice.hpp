/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:03:05 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/20 14:07:29 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class Ice: public AMateria {
    public:
        Ice();
        Ice(const Ice& obj);
        Ice& operator=(const Ice& obj);
        ~Ice();
        void use(ICharacter&) const;
};