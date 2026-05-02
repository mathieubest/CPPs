#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/Intern.hpp"

#include <ctime>
#include <cstdlib>

#define BOLD_BLUE "\033[1;34m"
#define RESET "\033[0m"

int main()
{
    Intern randomIntern;
    AForm* form = NULL;
    
    std::srand(static_cast<unsigned int>(std::time(0)));

    std::cout << BOLD_BLUE << "Intern creates a ShrubberyCreationForm" << RESET << std::endl;
    try {
        form = randomIntern.makeForm("shrubbery creation", "Jack");
        Bureaucrat yooki("Yooki", 1);
        yooki.signForm(*form);
        yooki.executeForm(*form);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << BOLD_BLUE << "Intern creates a RobotomyRequestForm" << RESET << std::endl;
    try {
        form = randomIntern.makeForm("robotomy request", "Jack");
        Bureaucrat raff("Raff", 1);
        raff.signForm(*form);
        raff.executeForm(*form);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << BOLD_BLUE << "Intern creates a PresidentialPardonForm" << RESET << std::endl;
    try {
        form = randomIntern.makeForm("presidential pardon", "Jack");
        Bureaucrat toto("Toto", 1);
        toto.signForm(*form);
        toto.executeForm(*form);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << BOLD_BLUE << "Intern creates a form that doesn't exist:" << RESET << std::endl;
    try {
        form = randomIntern.makeForm("unknown form", "Jack");
        Bureaucrat barbo("Barbo", 1);
        barbo.signForm(*form);
        barbo.executeForm(*form);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    delete form;
    return 0;
}
