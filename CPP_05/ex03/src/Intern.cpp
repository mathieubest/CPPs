#include "../include/Intern.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& copy) {
    (void)copy;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    const std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    int i;
    for (i = 0; i < 3; i++) {
        if (formName == forms[i])
            break;
    }

    switch(i) {
        case(0): {
            std:: cout << "Inter creates " << forms[i] << " form." << std::endl;
            return new ShrubberyCreationForm(target);
        }
        case(1): {
            std:: cout << "Inter creates " << forms[i] << " form." << std::endl;
            return new RobotomyRequestForm(target);
        }
        case(2): {
            std:: cout << "Inter creates " << forms[i] << " form." << std::endl;
            return new PresidentialPardonForm(target);
        }
        default:
            throw FormNotFoundException();
    }
}

const char* Intern::FormNotFoundException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {
    return RED "Form not found" RESET;
}