#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Name(), Sign(false), SignGrade(0), ExecGrade(0), _target("") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Name("PresidentialPardon"), Sign(false), SignGrade(72), ExecGrade(45) {
    this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj): Name(obj.Name), SignGrade(obj.SignGrade), ExecGrade(obj.ExecGrade), _target(obj._target) {
    this->Sign = obj.Sign;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
    if (this != obj) {
        this->Sign = obj.Sign;
        this->target = obj.target;
    }
    return *this;
}

std::string PresidentialPardonForm::getTarget() const {
    return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat &executor) const {
    if (executor.getGrade() < this->getExecGrade())
        throw GradeHighForExecutionException("");
    if (!this->getSign())
        throw FormNotSignedException("");
    std::cout << this->getTarget() << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    
}