#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        std::string _name;
        bool _isSigned;
        int _gradeToSign;
        int _gradeToExec;

    public:
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
        };
        
        Form();
        Form(std::string name, int gradeToSign, int gradeToExec);
        Form(const Form& copy);
        Form& operator=(const Form& other);
        ~Form();

        const std::string& getName() const;
        bool getSignature() const;
        int getGradeToSign() const;
        int getGradeToExec() const;

        void beSigned(const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif