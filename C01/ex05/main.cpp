/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:23:22 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/05 22:02:11 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (int ac ,char **av)
{
	Harl obj;

	if (ac > 1)
	{
		for (int i = 1; i < ac ; i++)
		{
			obj.complain(av[i]);
		}
	}
	else
		std::cout << "Invalid number of arguments" << std::endl;
	return (0);
}
