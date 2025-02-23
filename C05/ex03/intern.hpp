#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


class AForm;

class Intern {
    public:
        Intern();
		Intern(const Intern& obj);
		Intern& operator=(const Intern& obj);
		~Intern();
        AForm* createPresident( std::string &target );
        AForm* createShrubbery( std::string &target );
        AForm* createRobotomy( std::string &target );
        AForm *makeForm(std::string formName, std::string formTarget);
};