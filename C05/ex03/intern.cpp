#include "intern.hpp"
#include <iostream>

Intern::Intern()
{
    std::cout << "Default constructor called" << std::endl;
}

Intern::Intern(const Intern& obj)
{
    std::cout << "copy constructor called" << std::endl;
    *this = obj;
}

Intern::~Intern()
{
    std::cout << "Destructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& obj)
{
    (void)obj;
    return (*this);
}

AForm* Intern::createPresident( std::string &target ) {
    return (new PresidentialPardonForm(target));
}

AForm* Intern::createShrubbery( std::string &target ) {
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomy( std::string &target ) {
    return (new RobotomyRequestForm(target));
}

AForm* Intern::makeForm(std::string formName, std::string formTarget) {
    int whichForm = (formName == "shrubbery Creation") * 1 + (formName == "robotomy request") * 2 + (formName == "presidential pardon") * 3;
    if (!whichForm)
        throw "Form name doesn´t exist";
    
    typedef AForm* (Intern::*MemberFunctionPtr)( std::string& );

    MemberFunctionPtr functionArray[3] = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresident,
    };

    std::cout << "Intern creates " << formTarget << std::endl;
    return (this->*functionArray[whichForm - 1])(formTarget);
}