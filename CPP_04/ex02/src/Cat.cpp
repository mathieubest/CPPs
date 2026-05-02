#include "../include/Cat.hpp"

Cat::Cat() : AAnimal(), brain(new Brain()) {
    this->setType("Cat");
    std::cout << "Default constructor called for a cat." << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other), brain(new Brain(*other.brain)) {
    this->setType("Cat");
    std::cout << "Copy constructor called for a cat." << std::endl;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Destructor called for a cat." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        AAnimal::operator=(other);
        *brain = *other.brain;
        this->setType("Cat");
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow Meow!" << std::endl;
}