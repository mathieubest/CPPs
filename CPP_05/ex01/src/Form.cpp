#include "../include/Form.hpp"

#define RED "\033[0;31m"
#define RESET "\033[0m"

Form::Form() : _name("DefaultForm"), _isSigned(false), _gradeToSign(150), _gradeToExec(150) {}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : 
_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) 
{
    if (gradeToSign < 1 || gradeToExec < 1) {
        throw Form::GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExec > 150) {
        throw Form::GradeTooLowException();
    }
}

Form::Form(const Form& copy) : _name(copy.getName()), _isSigned(copy.getSignature()), _gradeToSign(copy.getGradeToSign()), _gradeToExec(copy.getGradeToExec()) {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        _name = other.getName();
        _isSigned = other.getSignature();
        _gradeToSign = other.getGradeToSign();
        _gradeToExec = other.getGradeToExec();
    }
    return *this;
}

Form::~Form() {}

const std::string& Form::getName() const {
    return _name;
}

bool Form::getSignature() const {
    return _isSigned;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExec() const {
    return _gradeToExec;
}

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() <= _gradeToSign) {
        _isSigned = true;
    } else {
        throw Bureaucrat::GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& out, const Form& f) {
    out << "Name: " << f.getName() << std::endl;
    if (f.getSignature()) {
        out << "Is signed: YES" << std::endl;
    } else {
        out << "Is signed: NO" << std::endl;
    }
    out << "Grade to sign: " << f.getGradeToSign() << std::endl
    << "Grade to execute: " << f.getGradeToExec() << std::endl;
    return out;
}

const char* Form::GradeTooHighException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {
    return RED "Form Error: Grade too high." RESET;
}

const char* Form::GradeTooLowException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {
    return RED "Form Error: Grade too low." RESET;
}