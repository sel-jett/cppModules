#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm;

class PresidentialPardonForm: public AForm {
    private:
        std::string _target;
        PresidentialPardonForm();
    public:
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm& obj);
		const PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);
        ~PresidentialPardonForm();
        std::string getTarget() const;
        virtual void execute(Bureaucrat &executor) const;
};