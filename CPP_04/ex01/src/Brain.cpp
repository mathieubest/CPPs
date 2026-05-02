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
        // for (int i = 0; i < 100; i++) {
        //     this->ideas[i] = other.ideas[i];
        // }
        *this = other;
    }
    return *this;
}

// void Brain::setIdea(int index, const std::string& idea) {
//     if (index >= 0 && index < 100) {
//         ideas[index] = idea;
//     } else {
//         std::cout << "Index out of bounds" << std::endl;
//     }
// }

// void Brain::printIdeas() const {
//     for (int i = 0; i < 100; i++) {
//         if (!ideas[i].empty()) {
//             std::cout << "Idea " << i << ": " << ideas[i] << std::endl;
//         }
//     }
// }

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        ideas[index] = idea;
    } else {
        std::cout << "Index out of range" << std::endl;
    }
}

void Brain::printIdeas() const {
    for (int i = 0; i < 100; i++) {
        if (!ideas[i].empty()) {
            std::cout << "Idea " << i << ": " << ideas[i] << std::endl;
        }
    }
}