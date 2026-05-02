#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default_PPF", 25, 5) {
    setTargetName("TBD");
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PPF", 25, 5) {
    checkTarget(target);
    setTargetName(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy) {
    targetName = copy.getTargetName();
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        targetName = other.getTargetName();
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

const std::string& PresidentialPardonForm::getTargetName() const {
    return targetName;
}

void PresidentialPardonForm::setTargetName(const std::string& name) {
    targetName = name;
}

void PresidentialPardonForm::performAction() const {
    std::cout << getTargetName() << " has been pardonned by Zaphod Beeblebrox." << std::endl;
}