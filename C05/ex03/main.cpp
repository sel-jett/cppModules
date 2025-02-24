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
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "intern.hpp"

int main (void)
{

	// ======================================== Test 1 ===============================================
	std::cout << "\033[1;32m// ======================================== Test 1 ===============================================\033[0m" << std::endl;

	Bureaucrat *a = new Bureaucrat("Salah Eddine", 150);
	ShrubberyCreationForm *b = new ShrubberyCreationForm("kali");

	a->signForm(*b);
	a->executeForm(*b);
	std::cout << *a ;
	delete b;
	delete a;

	// ========================================= Test 2 ==============================================
	std::cout << "\033[1;32m// ======================================== Test 2 ===============================================\033[0m" << std::endl;
	Bureaucrat *a2 = new Bureaucrat("rolecoster", 72);
	RobotomyRequestForm *b2 = new RobotomyRequestForm("cotton");

	a2->signForm(*b2);
	a2->executeForm(*b2);
	std::cout << *a2;
	delete b2;
	delete a2;

	// ========================================= Test 3 ==============================================
	std::cout << "\033[1;32m// ======================================== Test 3 ===============================================\033[0m" << std::endl;
	Bureaucrat *a3 = new Bureaucrat("laylow", 25);
	PresidentialPardonForm *b3 = new PresidentialPardonForm("yester");

	a3->signForm(*b3);
	a3->executeForm(*b3);
	std::cout << *a3;
	delete b3;
	delete a3;
	// ========================================= Test 4 ==============================================
	Bureaucrat *a4 = new Bureaucrat("laylow", 25);
	std::cout << "\033[1;32m// ======================================== Test 4 ===============================================\033[0m" << std::endl;
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	a4->signForm(*rrf);
	delete a4;
	delete rrf;

	return (0);
}
