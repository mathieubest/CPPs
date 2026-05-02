#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

#define RED "\033[0;31m"
#define RESET "\033[0m"

#include "AForm.hpp"

class AForm;

class Bureaucrat {
    private:
        std::string _name;
        int _grade;

    public:
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
        };

        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        const std::string& getName() const;
        int getGrade() const;
        void setGrade(int grade);
        void incrementGrade();
        void decrementGrade();

        void signForm(AForm& form);
        void executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif