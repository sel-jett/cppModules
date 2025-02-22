#include "intern.hpp"

Intern::Intern():_job("Uknown")
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
    if (this != &obj)
        _job = obj.getJob();
    return (*this);
}

std::string Intern::getJob( void ) const {
    return _job;
}

PresidentialPardonForm* Intern::createPresident( std::string &target ) {
    return (PresidentialPardonForm(target));
}

ShrubberyCreationForm* Intern::createShrubbery( std::string &target ) {
    return (ShrubberyCreationForm(target));
}

RobotomyRequestForm* Intern::createRobotomy( std::string &target ) {
    return (RobotomyRequestForm(target));
}

AForm* Intern::makeForm(std::string &formName, std::string &formTarget) {
    int whichForm = (formName == "Shrubbery Creation" * 1) + (formName == "Robotomy request" * 2) + (formName == "Presidential pardon" * 3);
    if (!whichForm)
        throw "Form name doesn´t exist";
    
    typedef void (Intern::*MemberFunctionPtr)();

    MemberFunctionPtr functionArray[3] = {
        &Intern::createShrubbery(formTarget);
        &Intern::createRobotomy(formTarget);
        &Intern::createPresident(formTarget);
    }

    std::cout << "Intern creates " << formTarget << std::endl;
    return (this->*functionArray[whichForm]);
}