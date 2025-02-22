#pragma once

#include "AForm.hpp"

class Bureaucrat;

class Aform;

class ShrubberyCreationForm: public AForm {
    private:
        std::string _target;
        ShrubberyCreationForm();
    public:
        ShrubberyCreationForm(std::string &target, std::string &Name, bool sign, int signGrade, int ExecGrade);
        ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
        ~ShrubberyCreationForm();
        std::string getTarget() const;
};