#pragma once

#include "AForm.hpp"

class Bureaucrat;

class Aform;

class PresidentialPardonForm: public AForm {
    private:
        std::string _target;
        PresidentialPardonForm();
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& obj);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);
        ~PresidentialPardonForm();
        std::string getTarget() const;
};