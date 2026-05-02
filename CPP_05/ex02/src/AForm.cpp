#include "../include/AForm.hpp"

AForm::AForm() : _name("DefaultForm"), _isSigned(false), _gradeToSign(150), _gradeToExec(150) {}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec) : 
_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) 
{
    if (gradeToSign < 1 || gradeToExec < 1) {
        throw AForm::GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExec > 150) {
        throw AForm::GradeTooLowException();
    }
}

AForm::AForm(const AForm& copy) : _name(copy.getName()), _isSigned(copy.getSignature()), _gradeToSign(copy.getGradeToSign()), _gradeToExec(copy.getGradeToExec()) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        _name = other.getName();
        _isSigned = other.getSignature();
        _gradeToSign = other.getGradeToSign();
        _gradeToExec = other.getGradeToExec();
    }
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::getSignature() const {
    return _isSigned;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExec() const {
    return _gradeToExec;
}

void AForm::setName(const std::string& name) {
    _name = name;
}

void AForm::setSignature(bool signature) {
    _isSigned = signature;
}

void AForm::setGradeToSign(int grade) {
    _gradeToSign = grade;
}

void AForm::setGradeToExec(int grade) {
    _gradeToExec = grade;
}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() <= _gradeToSign) {
        _isSigned = true;
    } else {
        throw Bureaucrat::GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& out, const AForm& f) {
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

const char* AForm::GradeTooHighException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {
    return RED "Form Error: Grade too high." RESET;
}

const char* AForm::GradeTooLowException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {
    return RED "Form Error: Grade too low." RESET;
}

void AForm::execute(Bureaucrat const & executor) const {
    if (!getSignature()) {
        throw std::runtime_error(RED "Form is not Signed." RESET);
    }
    if (executor.getGrade() > getGradeToExec()) {
        throw GradeTooLowException();
    }
    performAction();
}

void AForm::checkTarget(const std::string& target) {
    if (target.empty()) {
        throw std::invalid_argument(RED "Target Name cannot be empty." RESET);
    }
}