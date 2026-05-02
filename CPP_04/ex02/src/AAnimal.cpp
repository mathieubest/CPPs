#include "../include/Animal.hpp"

AAnimal::AAnimal() : _type("Unknown") {
    std::cout << "Default constructor called for an animal." << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type) {
    std::cout << "Copy constructor called for an animal." << std::endl;
}

AAnimal::~AAnimal() {
    std::cout << "Destructor called for an animal." << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    if (this != &other) {
        this->_type = other._type;
    }
    return *this;
}

const std::string& AAnimal::getType() const {
    return this->_type;
}

void AAnimal::setType(const std::string& type) {
    this->_type = type;
}