#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default_SCF", 145, 137) {
    setTargetName("TBD");
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("SCF", 145, 137)  {
    checkTarget(target);
    setTargetName(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy) {
    targetName = copy.getTargetName();
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        targetName = other.getTargetName();
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


const std::string& ShrubberyCreationForm::getTargetName() const {
    return targetName;
}

void ShrubberyCreationForm::setTargetName(const std::string& name) {
    targetName = name;
}

void ShrubberyCreationForm::performAction() const {
    std::string target = getTargetName();
    std::string filePath = target + "_shrubbery";

    std::ofstream outFile(filePath.c_str());
    if (!outFile) {
        std::cerr << RED << "Error: could not create file at " << filePath << RESET << std::endl;
        throw std::runtime_error(RED "File creation failed" RESET);
    }

    outFile << "       _-_" << std::endl;
    outFile << "    /~~   ~~\\" << std::endl;
    outFile << " /~~         ~~\\" << std::endl;
    outFile << "{               }" << std::endl;
    outFile << " \\  _-     -_  /" << std::endl;
    outFile << "   ~  \\\\ //  ~" << std::endl;
    outFile << "_- -   | | _- _" << std::endl;
    outFile << "  _ -  | |   -_" << std::endl;
    outFile << "      // \\\\" << std::endl;
    outFile.close();
}
