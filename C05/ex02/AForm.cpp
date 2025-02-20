/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:44:58 by sel-jett          #+#    #+#             */
/*   Updated: 2024/12/04 22:14:31 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAForm.hpp"

AForm::AForm():Name("Uknown"), Sign(false), SignGrade(0), ExecGrade(0)
{
	std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(const AForm& obj): Name(obj.Name), Sign(obj.Sign), SignGrade(obj.SignGrade), ExecGrade(obj.ExecGrade)
{
	std::cout << "Copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& obj)
{
	if (this != &obj)
		Sign = obj.getSign();
	return *this;
}

AForm::~AForm()
{
	std::cout << "Destructor called" << std::endl;
}

AForm::AForm(std::string const name, bool Sign, const int SignGrade, const int ExecGrade): Name(name), SignGrade(SignGrade), ExecGrade(ExecGrade)
{
	this->Sign = Sign;
}

std::string const AForm::getName() const
{
	return (Name);
}

bool AForm::getSign() const
{
	return Sign;
}

int AForm::getSignGrade() const
{
	return (SignGrade);
}

int AForm::getExecGrade() const
{
	return (ExecGrade);
}

void AForm::beSigned(Bureaucrat &a)
{
	if (a.getGrade() >=  this->SignGrade)
		Sign = true;
	else
		throw (GradeTooHighException());

}

std::ostream& operator<<(std::ostream& stream, const AForm &x)
{
	stream << x.getName() << ", AForm is Signed : " << x.getSign() << ", required sign grade : " << x.getSignGrade() << ", execution Grade : " << x.getExecGrade() << std::endl;
	return (stream);
}
