#pragma once

#include "AForm.hpp"

class Bureaucrat;

class Aform;

class RobotomyRequestForm: public AForm {
    private:
        std::string _target;
        RobotomyRequestForm();
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
        ~RobotomyRequestForm();
        std::string getTarget() const;
};