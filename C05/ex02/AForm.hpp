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

class AForm {
	private:
		std::string const Name;
		bool Sign;
		const int SignGrade;
		const int ExecGrade;
	public:
		AForm();
		AForm(const AForm& obj);
		AForm& operator=(const AForm& obj);
		virtual ~AForm();
		AForm(std::string const name, bool Sign, const int SignGrade, const int ExecGrade);
		std::string const getName() const;
		bool getSign() const;
		int getSignGrade() const;
		int getExecGrade() const;
		void beSigned(Bureaucrat &a);

		virtual void execute(Bureaucrat &executor) const = 0;

		class GradeTooHighException: public std::exception{
			public:
				const char *what() const throw() {return "GradeTooHighException: Grade is too high";}
		};

		class GradeTooLowException: public std::exception{
			public:
				const char *what() const throw() {return "GradeTooLowException: Grade is too Low";}
		};

		class GradeHighForExecutionException: public std::exception{
			public:
				const char *what() const throw() {return "GradeHighForExecutionException: Grade of is too high to be executed";}
		};
		
		class FormNotSignedException: public std::exception{
			public:
				const char *what() const throw() {return "FormNotSignedException: Form Needs to be signed";}
		};

};

std::ostream& operator<<(std::ostream& stream, const AForm &x);
