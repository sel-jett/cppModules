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
        AForm* createPresident( std::string &target );
        AForm* createShrubbery( std::string &target );
        AForm* createRobotomy( std::string &target );
        std::string getJob( void ) const;
        AForm *makeForm(std::string formName, std::string formTarget);
};