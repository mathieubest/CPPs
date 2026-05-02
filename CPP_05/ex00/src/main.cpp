#include "../include/Bureaucrat.hpp"

#define BOLD_BLUE "\033[1;34m"
#define RESET "\033[0m"


int main()
{
    std::cout << BOLD_BLUE << "Testing a default Bureaucrat" << RESET << std::endl;
    try {
        Bureaucrat def;
        std::cout << def;
        std::cout << "Incrementing grade." << std::endl;
        def.incrementGrade();
        std::cout << def;
        std::cout << "Decrementing grade." << std::endl;
        def.decrementGrade();
        std::cout << def;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    
    std::cout << std::endl << BOLD_BLUE << "Testing an instance of a Bureaucrat with a grade too low" << RESET << std::endl;
    try {
        Bureaucrat sam("Sam", 200);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << BOLD_BLUE << "Testing an instance of a Bureaucrat with a grade too high" << RESET << std::endl;
    try {
        Bureaucrat tom("Tom", 0);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << BOLD_BLUE << "Testing an incrementation too high" << RESET << std::endl;
    try {
        Bureaucrat don("Dona", 1);
        std::cout << don;
        std::cout << "Incrementing grade." << std::endl;
        don.incrementGrade();
        std::cout << don;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << BOLD_BLUE << "Testing an decrementation too low" << RESET << std::endl;
    try {
        Bureaucrat tuti("Tuti", 150);
        std::cout << tuti;
        std::cout << "Decrementing grade." << std::endl;
        tuti.decrementGrade();
        std::cout << tuti;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    return (0);
}
