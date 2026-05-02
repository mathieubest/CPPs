#include "../include/Span.hpp"

#define BOLD_BLUE "\033[1;34m"
#define BOLD_YLO "\033[1;33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

int main() {

    //? Test 1
    try {
        std::cout << BOLD_BLUE << "=== Test 1 ===" << RESET << std::endl;
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(5);
        sp.addNumber(10);
        std::cout << BOLD_YLO << "== Printing out the vector ==" << RESET << std::endl;
        std::cout << GREEN << "Vector: " RESET;
        sp.printVector();
        std::cout << BOLD_YLO << "== Testing shortest and longest span functions ==" << RESET << std::endl;
        sp.shortestSpan();
        sp.longestSpan();
    } catch (std::exception& e) {
        std::cerr << "Runtime error: " << RED << e.what() << RESET << std::endl;
    }

    //? Test 2
    try {
        std::cout << std::endl << BOLD_BLUE << "=== Test 2 ===" << RESET << std::endl;
        Span sp(100);
        sp.addXNumbers(100);
        std::cout << BOLD_YLO << "== Printing out the vector ==" << RESET << std::endl;
        std::cout << GREEN << "Vector: " RESET;
        sp.printVector();
        std::cout << BOLD_YLO << "== Testing shortest and longest span functions ==" << RESET << std::endl;
        sp.shortestSpan();
        sp.longestSpan();
    } catch (std::exception& e) {
        std::cerr << "Runtime error: " << RED << e.what() << RESET << std::endl;
    }

    //? Test 2 
    try {
        std::cout << std::endl << BOLD_BLUE << "=== Test 3 / Should Fail ===" << RESET << std::endl;
        Span sp(2);
        sp.addXNumbers(100);
        std::cout << std::endl << BOLD_YLO << "=== Printing out the vector ===" << RESET << std::endl;
        std::cout << GREEN << "Vector: " RESET;
        sp.printVector();
        std::cout << BOLD_YLO << "=== Testing shortest and longest span functions ===" << RESET << std::endl;
        sp.shortestSpan();
        sp.longestSpan();
    } catch (std::exception& e) {
        std::cerr << "Runtime error: " << RED << e.what() << RESET << std::endl;
    }
}