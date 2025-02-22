#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("", false, 0, 0), _target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreation", false, 145, 137) {
    this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj): Name(obj.Name), SignGrade(obj.SignGrade), ExecGrade(obj.ExecGrade), _target(obj._target) {
    this->Sign = obj.Sign;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) {
    if (this != obj) {
        this->Sign = obj.Sign;
        this->target = obj.target;
    }
    return *this;
}

std::string ShrubberyCreationForm::getTarget() const {
    return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat &executor) const {
    if (executor.getGrade() < this->getExecGrade())
        throw GradeHighForExecutionException("");
    if (!this->getSign())
        throw FormNotSignedException("");
    std::ofstream file1(this->getTarget() + "_Shrubbery");
    if (file1.is_open()) {
        file << "    oxoxoo    ooxoo" std::endl;
        file << "  ooxoxo oo  oxoxooo" std::endl;
        file << " oooo xxoxoo ooo ooox" std::endl;
        file << " oxo o oxoxo  xoxxoxo" std::endl;
        file << "  oxo xooxoooo o ooo" std::endl;
        file << "    ooo\\oo\\  /o/o" std::endl;
        file << "        \\  \\/ /" std::endl;
        file << "         |   /" std::endl;
        file << "         |  |" std::endl;
        file << "         | D|" std::endl;
        file << "         |  |" std::endl;
        file << "         |  |" std::endl;
        file << "         |  |" std::endl;
        file << "  ______/____\\____" std::endl;
        file1.close();
    } else {
        std::cerr << "Couldn´t open file" << std::endl;
    }
}