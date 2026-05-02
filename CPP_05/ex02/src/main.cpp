#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

#include <ctime>
#include <cstdlib>

#define BOLD_BLUE "\033[1;34m"
#define RESET "\033[0m"

int main()
{
    std::srand(static_cast<unsigned int>(std::time(0)));
    std::cout << BOLD_BLUE << "Testing some ShrubberyCreationForms that should work perfectly" << RESET << std::endl;
    try {
        ShrubberyCreationForm def;
        ShrubberyCreationForm sh("Greetings");
        Bureaucrat bob("Bob", 90);
        bob.signForm(def);
        bob.signForm(sh);
        bob.executeForm(def);
        bob.executeForm(sh);
    } catch(const std::exception& e) {
        std::cerr << "Caught execption: " << e.what() << std::endl;
    }

    std::cout << std::endl << BOLD_BLUE << "Testing ShrubberyCreationForm that isn't signed" << RESET << std::endl;
    try {
        ShrubberyCreationForm sh("Signatures");
        Bureaucrat bob("Bob", 90);
        bob.executeForm(sh);
    } catch(const std::exception& e) {
        std::cerr << "Caught execption: " << e.what() << std::endl;
    }


    std::cout << std::endl << BOLD_BLUE << "Testing ShrubberyCreationForm that can't be signed by the bureaucrat because grade too low" << RESET << std::endl;
    try {
        ShrubberyCreationForm sh("Signatures");
        Bureaucrat bob("Bob", 148);
        bob.signForm(sh);
        bob.executeForm(sh);
    } catch(const std::exception& e) {
        std::cerr << "Caught execption: " << e.what() << std::endl;
    }
    
    std::cout << std::endl << BOLD_BLUE << "Testing some RobotomyRequestForms that should work perfectly" << RESET << std::endl;
    try {
        RobotomyRequestForm def;
        RobotomyRequestForm uno("Uno");
        Bureaucrat soul("Soul", 10);
        soul.signForm(def);
        soul.signForm(uno);
        soul.executeForm(def);
        soul.executeForm(uno);
    } catch (const std::exception& e) {
        std::cerr << "Caught exeception: " << e.what() << std::endl;
    }

    std::cout << std::endl << BOLD_BLUE << "Testing some PresidentialPardonForms that should work perfectly" << RESET << std::endl;
    try {
        PresidentialPardonForm def;
        PresidentialPardonForm uno("Uno");
        Bureaucrat trump("Trump", 2);
        trump.signForm(def);
        trump.signForm(uno);
        trump.executeForm(def);
        trump.executeForm(uno);
    } catch (const std::exception& e) {
        std::cerr << "Caught exeception: " << e.what() << std::endl;
    }
    return (0);
}
