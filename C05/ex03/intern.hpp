#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


class AForm;

class Intern {
    private:
        std::string _job;
    public:
        Intern();
		Intern(const Intern& obj);
		Intern& operator=(const Intern& obj);
		~Intern();
        PresidentialPardonForm* createPresident( void );
        ShrubberyCreationForm* createShrubbery( void );
        RobotomyRequestForm* createRobotomy( void );
        std::string getJob( void ) const;
        AForm *makeForm(std::string &formName, std::string &formTarget);
};