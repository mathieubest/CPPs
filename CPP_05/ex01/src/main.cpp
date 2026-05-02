#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

#define BOLD_BLUE "\033[1;34m"
#define RESET "\033[0m"

int main()
{
    std::cout << BOLD_BLUE << "Testing a Form that should throw an exception" << RESET << std::endl;
    try {
        Form br("BlackRock", 200, 10);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << BOLD_BLUE << "Testing a Bureaucrat that has the level to sign a Form" << RESET << std::endl;
    try {
        Bureaucrat don("Dona", 20);
        std::cout << don;
        don.incrementGrade();
        std::cout << "Incrementing grade of " << don.getName() << std::endl;
        std::cout << don;
        Form tax("Taxes", 100, 100);
        std::cout << tax;
        don.signForm(tax);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << BOLD_BLUE << "Testing a Bureaucrat that doesn't have the level to sign a Form" << RESET << std::endl;
    try {
        Bureaucrat sam("Sam", 150);
        std::cout << sam;
        Form ts("Top Secret", 5, 1);
        std::cout << ts;
        sam.signForm(ts);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    return (0);
}
