/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:33:52 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/04 22:39:36 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main (int ac, char **av)
{
	std::string filename;
	std::string s1;
	std::string s2;

	if (ac != 4)
		std::cerr << "invalid number of arguments " << std::endl;
	Sed sed(av[1], av[2], av[3]);
	sed.search_and_replace();
}
