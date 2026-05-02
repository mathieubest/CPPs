#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

class Bureaucrat;

class AForm {
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
        
        AForm();
        AForm(std::string name, int gradeToSign, int gradeToExec);
        AForm(const AForm& copy);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        const std::string& getName() const;
        bool getSignature() const;
        int getGradeToSign() const;
        int getGradeToExec() const;

        void setName(const std::string& name);
        void setSignature(bool signature);
        void setGradeToSign(int grade);
        void setGradeToExec(int grade);

        void beSigned(const Bureaucrat& b);
        void execute(Bureaucrat const & executor) const;
        void checkTarget(const std::string& target);
        virtual void performAction() const = 0;
    };

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif