#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery", false, 0, 0), _target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("Shrubbery", false, 145, 137) {
    this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj): AForm(obj) {
    *this = obj;
}

const ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) {
    if (this != &obj) {
        AForm::operator=(obj);
        this->_target = obj.getTarget();
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

std::string ShrubberyCreationForm::getTarget() const {
    return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat &executor) const {
    if (executor.getGrade() < this->getExecGrade())
        throw GradeHighForExecutionException();
    if (!this->getSign())
        throw FormNotSignedException();
    std::ofstream file1((this->getTarget() + "_Shrubbery").c_str());
    if (file1.is_open()) {
        file1 << "    oxoxoo    ooxoo" << std::endl;
        file1 << "  ooxoxo oo  oxoxooo" << std::endl;
        file1 << " oooo xxoxoo ooo ooox" << std::endl;
        file1 << " oxo o oxoxo  xoxxoxo" << std::endl;
        file1 << "  oxo xooxoooo o ooo" << std::endl;
        file1 << "    ooo\\oo\\  /o/o" << std::endl;
        file1 << "        \\  \\/ /" << std::endl;
        file1 << "         |   /" << std::endl;
        file1 << "         |  |" << std::endl;
        file1 << "         | D|" << std::endl;
        file1 << "         |  |" << std::endl;
        file1 << "         |  |" << std::endl;
        file1 << "         |  |" << std::endl;
        file1 << "  ______/____\\____" << std::endl;
        file1.close();
    } else {
        std::cerr << "Couldn´t open file" << std::endl;
    }
}