#include "../include/Dog.hpp"

Dog::Dog() : Animal() {
    this->setType("Dog");
    std::cout << "Default constructor called for a dog." << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    this->setType("Dog");
    std::cout << "Copy constructor called for a dog." << std::endl;
}

Dog::~Dog() {
    std::cout << "Default destructor called for a dog." << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        this->setType("Dog");
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof Woof!" << std::endl;
}