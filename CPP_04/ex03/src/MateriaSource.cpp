#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++) {
        this->_materias[i] = NULL;
    }
}   

MateriaSource::MateriaSource(const MateriaSource& copy)
{
    *this = copy;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++) {
        if (this->_materias[i]) {
            delete this->_materias[i];
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            if (this->_materias[i]) {
                delete this->_materias[i];
            }
            if (other._materias[i]) {
                this->_materias[i] = other._materias[i]->clone();
            }
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (m) {
        for (int i = 0; i < 4; i++) {
            if (!this->_materias[i]) {
                this->_materias[i] = m;
                std::cout << "Materia " << m->getType() << " learned" << std::endl;
                return;
            }
        }
    }
    std::cout << "Inventory is full... Couldn't learn " << m->getType() << std::endl;
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
    for (int i = 0; i < 4; i++) {
        if (this->_materias[i] && this->_materias[i]->getType() == type) {
            std::cout << "Created " << type << std::endl;
            return this->_materias[i]->clone();
        }
    }
    std::cout << "No materia of type " << type << " found" << std::endl;
    return NULL;
}
