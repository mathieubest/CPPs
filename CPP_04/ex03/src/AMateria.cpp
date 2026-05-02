#include "../include/AMateria.hpp"

AMateria::AMateria() : _type("default") {}

AMateria::AMateria(std::string const& type) : _type(type) {}

AMateria::AMateria(const AMateria& copy) : _type(copy._type) {}

AMateria::~AMateria() {}

AMateria& AMateria::operator=(const AMateria& other)
{
    if(this != &other) {
        _type = other._type;
    }
    return *this;
}

std::string const& AMateria::getType() const
{
    return this->_type;
}

void AMateria::use(ICharacter& target)
{
    if (this->_type == "ice") {
        std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    } else if (this->_type == "cure") {
        std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
    } else {
        std::cout << "Invalid type" << std::endl;
    }
}
