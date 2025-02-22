#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential", false, 0, 0), _target("") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("Presidential", false, 25, 5) {
    this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj): AForm(obj) {
    *this = obj;
}

const PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
    if (this != &obj) {
        AForm::operator=(obj);
        this->_target = obj.getTarget();
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

std::string PresidentialPardonForm::getTarget() const {
    return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat &executor) const {
    if (executor.getGrade() < this->getExecGrade())
        throw GradeHighForExecutionException();
    if (!this->getSign())
        throw FormNotSignedException();
    std::cout << this->getTarget() << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    
}