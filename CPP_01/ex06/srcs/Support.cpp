#include "../includes/Support.hpp"

void invalid_arguments(void) {
    std::cerr << BOLD_RED << "Invalid input..." << RESET << std::endl;
    std::cerr << BOLD_GREEN << "Usage: ./main \"LEVEL\"" << std::endl;
    std::cerr << "Levels: \"DEBUG\" \"INFO\" \"WAARNING\" \"ERROR\"" << RESET << std::endl; 
}

