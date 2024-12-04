/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:37:28 by sel-jett          #+#    #+#             */
/*   Updated: 2024/12/04 22:16:05 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		std::string const Name;
		bool Sign;
		const int SignGrade;
		const int ExecGrade;
	public:
		Form();
		Form(const Form& obj);
		Form& operator=(const Form& obj);
		~Form();
		Form(std::string const name, bool Sign, const int SignGrade, const int ExecGrade);
		std::string const getName() const;
		bool getSign() const;
		int getSignGrade() const;
		int getExecGrade() const;
		void beSigned(Bureaucrat &a);
		class GradeTooHighException: public std::exception{
			public:
				const char *what() const throw() {return "GradeTooHighException: Grade is too high";}
		};
		class GradeTooLowException: public std::exception{
			public:
				const char *what() const throw() {return "GradeTooLowException: Grade is too Low";}
		};

};

std::ostream& operator<<(std::ostream& stream, const Form &x);
