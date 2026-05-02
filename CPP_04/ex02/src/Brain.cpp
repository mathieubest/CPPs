#include "../include/Brain.hpp"

Brain::Brain() {
    std::cout << "Default constructor called for a brain." << std::endl;
}

Brain::Brain(const Brain& other) {
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = other.ideas[i];
    }
    std::cout << "Copy constructor called for a brain." << std::endl;
}

Brain::~Brain() {
    std::cout << "Destructor called for a brain." << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        *this = other;
    }
    return *this;
}