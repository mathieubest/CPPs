#include "../include/Ice.hpp"

Ice::Ice()
{
    this->_type = "ice";
}

Ice::Ice(const Ice& copy)
{
    *this = copy;
}

Ice::~Ice() {}

Ice& Ice::operator=(const Ice& other)
{
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

AMateria* Ice::clone() const
{
    // std::cout << "Cloning Ice" << std::endl;
    return new Ice(*this);
}
