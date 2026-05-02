#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
    std::cout << "Default constructor called for a WrongAnimal." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {
    std::cout << "Copy constructor called for a WrongAnimal." << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Destructor called for a WrongAnimal." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) {
        this->_type = other._type;
    }
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound!" << std::endl;
}

const std::string& WrongAnimal::getType() const {
    return this->_type;
}

void WrongAnimal::setType(const std::string& type) {
    this->_type = type;
}