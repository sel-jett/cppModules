/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:50:40 by sel-jett          #+#    #+#             */
/*   Updated: 2024/12/04 19:26:28 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main (void)
{
	try {
		Bureaucrat *a = new Bureaucrat("Salah Eddine", 160);
		a->decrementBureaucratGrade();
		std::cout << *a ;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat *a = new Bureaucrat("Salah Eddine", 1);
		for (int i = 0; i < 140; ++i)
		{
			a->decrementBureaucratGrade();
		}
		a->decrementBureaucratGrade();
		std::cout << *a ;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
