/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:33:52 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/04 23:19:20 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main (int ac, char **av)
{
	std::string filename;
	std::string s1;
	std::string s2;

	if (ac != 4 || !av[2][0])
	{
		std::cerr << "invalid arguments " << std::endl;
		return (0);
	}
	Sed sed(av[1], av[2], av[3]);
	sed.search_and_replace();
	return (0);
}
