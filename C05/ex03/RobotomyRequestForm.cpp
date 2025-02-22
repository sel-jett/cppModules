#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy", false, 0, 0), _target("") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("Robotomy", false, 72, 45) {
    this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj): AForm(obj) {
    *this = obj;
}

const RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) {
    if (this != &obj) {
        AForm::operator=(obj);
        this->_target = obj.getTarget();
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

std::string RobotomyRequestForm::getTarget() const {
    return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat &executor) const {
    if (executor.getGrade() < this->getExecGrade())
        throw GradeHighForExecutionException();
    if (!this->getSign())
        throw FormNotSignedException();
    std::cout << this->getTarget() << "Has been robotimized successfully 50% of the time" << std::endl;
}