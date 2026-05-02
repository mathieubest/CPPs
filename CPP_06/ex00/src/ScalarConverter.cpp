#include "../include/ScalarConverter.hpp"
#include "../include/Utils.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
    *this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& str_literal) {
    if (str_literal.empty()) {
        throw ScalarConverter::NoInputException();
    }

    //# Handle special strings
    if (isSpecialString(str_literal)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        
        if (str_literal == "nanf" || str_literal == "nan") {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        } else if (str_literal == "+inff" || str_literal == "+inf") {
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        } else if (str_literal == "-inff" || str_literal == "-inf") {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
        return;
    }

    //# Handle char literals
    if (str_literal.length() == 1 && !isdigit(str_literal[0])) {
        char c = str_literal[0];
        if (!isDisplayableChar(c)) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: '" << c << "'" << std::endl;
        }
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        return;
    }

    //# Handle numeric literals
    if (isFloatLiteral(str_literal)) {
        float f = std::strtof(str_literal.c_str(), NULL);
        if (!isDisplayableChar(static_cast<char>(f))) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
        }
        std::cout << "int: " << static_cast<int>(f) << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
    }
    else if (isDoubleLiteral(str_literal)) {
        double d = std::strtod(str_literal.c_str(), NULL);
        if (!isDisplayableChar(static_cast<char>(d))) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
        }
        std::cout << "int: " << static_cast<int>(d) << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
    else if (isIntLiteral(str_literal)) {
        int i = std::strtol(str_literal.c_str(), NULL, 10);
        if (!isDisplayableChar(static_cast<char>(i))) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
        }
        std::cout << "int: " << i << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(i) << std::endl;
    }
    else {
        throw ScalarConverter::InvalidInputException();
    }
}

const char* ScalarConverter::NoInputException::what() const throw() {
    return "No input provided.";
}

const char* ScalarConverter::InvalidInputException::what() const throw() {
    return "Invalid input provided.";
}