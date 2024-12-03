/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:13:34 by sel-jett          #+#    #+#             */
/*   Updated: 2024/12/03 18:45:48 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>

class Bureaucrat {
    private:
        std::string const Name;
        int               Grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat& obj);
        Bureaucrat& operator=(const Bureaucrat& obj);
        ~Bureaucrat();
        Bureaucrat(std::string const name, int grade);
        const std::string& getName( void ) const;
        int getGrade( void ) const;
        void incrementBureaucratGrade( void );
        void decrementBureaucratGrade( void );

        class GradeTooHighException: public std::exception{
            public:
                const char *what() const throw() {return "GradeTooHighException: Grade is too high";}
        };
        class GradeTooLowException: public std::exception{
            public:
                const char *what() const throw() {return "GradeTooLowException: Grade is too Low";}
        };
};
