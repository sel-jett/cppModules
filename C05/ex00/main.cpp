/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:50:40 by sel-jett          #+#    #+#             */
/*   Updated: 2024/12/03 18:52:44 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main (void)
{
	Bureaucrat *a = new Bureaucrat("Salah Eddine", 150);
	std::cout << a->getName() << "'s grade is " << a->getGrade() << std::endl;
	for (int i = 0; i <= 140; ++i)
	{
		a->decrementBureaucratGrade();
	}
	a->decrementBureaucratGrade();
	std::cout << a->getName() << "'s grade is " << a->getGrade() << std::endl;
	return (0);
}
