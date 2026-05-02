#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
    public:
        static void convert(const std::string& str_literal);

    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& copy);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

        class InvalidInputException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class NoInputException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

#endif