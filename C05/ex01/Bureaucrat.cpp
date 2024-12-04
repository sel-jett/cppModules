/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:11:17 by sel-jett          #+#    #+#             */
/*   Updated: 2024/12/04 21:55:15 by sel-jett         ###   ########.fr       */
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

void Bureaucrat::signForm(Form &form)
{
    try {
        form.beSigned(*this);
        std::cout << this->Name << " signed " << form.getName() << std::endl;
    } catch(std::exception & e)
    {
        std::cout << this->Name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
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

std::ostream& operator<<(std::ostream& stream, const Bureaucrat &x)
{
    stream << x.getName() << ", bureaucrat grade " << x.getGrade() << std::endl;
    return (stream);
}
