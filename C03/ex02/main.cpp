/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 07:06:20 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/18 08:11:57 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main( void )
{
    FragTrap salah("Salah");
    salah.attack("nrjs");
    salah.takeDamage(100);
    salah.beRepaired(1);
    salah.highFivesGuys();
    return (0);
}