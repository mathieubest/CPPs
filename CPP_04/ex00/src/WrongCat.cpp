#include "../include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    this->setType("WrongCat");
    std::cout << "Default constructor called for a WrongCat." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    this->setType("WrongCat");
    std::cout << "Copy constructor called for a WrongCat." << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "Default destructor called for a WrongCat." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
        this->setType("WrongCat");
    }
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}