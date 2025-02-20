/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:50:40 by sel-jett          #+#    #+#             */
/*   Updated: 2024/12/04 22:22:28 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main (void)
{

	// ======================================== Test 1 ===============================================
	Bureaucrat *a = new Bureaucrat("Salah Eddine", 150);
	Form *b = new Form("Form1", false, 10, 10);

	a->signForm(*b);
	std::cout << *a ;

	// ========================================= Test 2 ==============================================
	Bureaucrat *a2 = new Bureaucrat("Jett", 1);
	Form *b2 = new Form("Form2", false, 10, 10);

	a2->signForm(*b2);
	std::cout << *a2;

	return (0);
}
