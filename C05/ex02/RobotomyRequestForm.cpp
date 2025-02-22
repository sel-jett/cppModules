#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Name(), Sign(false), SignGrade(0), ExecGrade(0), _target("") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Name("RobotomyRequest"), Sign(false), SignGrade(72), ExecGrade(45) {
    this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj): Name(obj.Name), SignGrade(obj.SignGrade), ExecGrade(obj.ExecGrade), _target(obj._target) {
    this->Sign = obj.Sign;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) {
    if (this != obj) {
        this->Sign = obj.Sign;
        this->target = obj.target;
    }
    return *this;
}

std::string RobotomyRequestForm::getTarget() const {
    return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat &executor) const {
    if (executor.getGrade() < this->getExecGrade())
        throw GradeHighForExecutionException(" So The robotomy failed");
    if (!this->getSign())
        throw FormNotSignedException(" So The robotomy failed");
    std::cout << this->getTarget() << "Has been robotimized successfully 50% of the time" << std::endl;
}