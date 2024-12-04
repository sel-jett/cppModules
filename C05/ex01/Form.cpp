/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:44:58 by sel-jett          #+#    #+#             */
/*   Updated: 2024/12/04 22:14:31 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():Name("Uknown"), Sign(false), SignGrade(0), ExecGrade(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Form::Form(const Form& obj): Name(obj.Name), Sign(obj.Sign), SignGrade(obj.SignGrade), ExecGrade(obj.ExecGrade)
{
	std::cout << "Copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& obj)
{
	if (this != &obj)
		Sign = obj.getSign();
	return *this;
}

Form::~Form()
{
	std::cout << "Destructor called" << std::endl;
}

Form::Form(std::string const name, bool Sign, const int SignGrade, const int ExecGrade): Name(name), SignGrade(SignGrade), ExecGrade(ExecGrade)
{
	this->Sign = Sign;
}

std::string const Form::getName() const
{
	return (Name);
}

bool Form::getSign() const
{
	return Sign;
}

int Form::getSignGrade() const
{
	return (SignGrade);
}

int Form::getExecGrade() const
{
	return (ExecGrade);
}

void Form::beSigned(Bureaucrat &a)
{
	if (a.getGrade() >=  this->SignGrade)
		Sign = true;
	else
		throw (GradeTooLowException());

}

std::ostream& operator<<(std::ostream& stream, const Form &x)
{
	stream << x.getName() << ", Form is Signed : " << x.getSign() << ", required sign grade : " << x.getSignGrade() << ", execution Grade : " << x.getExecGrade() << std::endl;
	return (stream);
}
