/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:11:17 by sel-jett          #+#    #+#             */
/*   Updated: 2024/12/03 18:51:29 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():Name("Uknown"), Grade(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
{
    std::cout << "copy constructor called" << std::endl;
    *this = obj;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
    if (this != &obj)
        Grade = obj.getGrade();
    return (*this);
}

Bureaucrat::Bureaucrat(std::string const name, int grade): Name(name)
{
    this->Grade = grade;
}

const std::string& Bureaucrat::getName() const {
    return (Name);
}

int Bureaucrat::getGrade( void ) const {
    return (Grade) ;
}

void Bureaucrat::incrementBureaucratGrade( void ) {
    try {
        if ((Grade - 1) < 1)
            throw GradeTooLowException();
        else
            Grade--;
    } catch(std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
}

void Bureaucrat::decrementBureaucratGrade( void ) {
    try {
        if ((Grade + 1) > 150)
            throw GradeTooHighException();
        else
            Grade++;
    } catch(std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
}
