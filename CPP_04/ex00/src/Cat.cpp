#include "../include/Cat.hpp"

Cat::Cat() : Animal() {
    this->setType("Cat");
    std::cout << "Default constructor called for a cat." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    this->setType("Cat");
    std::cout << "Copy constructor called for a cat." << std::endl;
}

Cat::~Cat() {
    std::cout << "Destructor called for a cat." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        this->setType("Cat");
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow Meow!" << std::endl;
}