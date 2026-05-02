#include "../include/RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default_RRF", 72, 45) {
    setTargetName("TBD");
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RRF", 72, 45) {
    checkTarget(target);
    setTargetName(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy) {
    targetName = copy.getTargetName();
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        targetName = other.getTargetName();
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string& RobotomyRequestForm::getTargetName() const {
    return targetName;
}

void RobotomyRequestForm::setTargetName(const std::string& name) {
    targetName = name;
}

void RobotomyRequestForm::performAction() const {
    std::cout << "\a" << "BRRR... DRILLING NOISES!" << std::endl;

    if (std::rand() % 2 == 0) {
        std::cout << GREEN << "[" << getTargetName() << "] has been robotomized." << RESET << std::endl;
    } else {
        std::cout << RED << "Robotomy failed for [" << getTargetName() << "]!" << RESET << std::endl;
    }
}
