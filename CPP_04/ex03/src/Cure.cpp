#include "../include/Cure.hpp"

Cure::Cure()
{
    this->_type = "cure";
}

Cure::Cure(const Cure& copy)
{
    *this = copy;
}

Cure::~Cure() {}

Cure& Cure::operator=(const Cure& other)
{
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

AMateria* Cure::clone() const
{
    // std::cout << "Cloning" << std::endl;
    return new Cure(*this);
}
