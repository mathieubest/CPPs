#include "../include/Animal.hpp"

Animal::Animal() : _type("Unknown") {
    std::cout << "Default constructor called for an animal." << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type) {
    std::cout << "Copy constructor called for an animal." << std::endl;
}

Animal::~Animal() {
    std::cout << "Destructor called for an animal." << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        this->_type = other._type;
    }
    return *this;
}

void Animal::makeSound() const {
    std::cout << "Animal sound!" << std::endl;
}

const std::string& Animal::getType() const {
    return this->_type;
}

void Animal::setType(const std::string& type) {
    this->_type = type;
}