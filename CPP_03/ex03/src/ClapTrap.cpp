#include "../includes/ClapTrap.hpp"
#include "../includes/ColorCodes.hpp"
#include "../includes/Emojis.hpp"

ClapTrap::ClapTrap() : _Name("Default"), _hitPoint(10), _Energy(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _Name << " created with default constructor" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _Name(name), _hitPoint(10), _Energy(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _Name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _Name(other._Name), _hitPoint(other._hitPoint), _Energy(other._Energy), _attackDamage(other._attackDamage) {
    std::cout << "ClapTrap " << _Name << " created with copy constructor" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _Name << " destroyed" << std::endl;
}


ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        _Name = other._Name;
        _hitPoint = other._hitPoint;
        _Energy = other._Energy;
        _attackDamage = other._attackDamage;
    }
    std::cout << "ClapTrap " << _Name << " assigned from another ClapTrap" << std::endl;
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (this->_Energy > 0 && this->_hitPoint > 0) {
        this->_Energy--;
        std::cout << SWORD SWORD << " ClapTrap " << _Name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    } else if (this->_Energy <= 0) {
        std::cout << RED << "ClapTrap " << _Name << " can't attack... Out of energy." << RESET << std::endl;
    } else {
        std::cout << RED << "ClapTrap " << _Name << " can't attack... No more health." << RESET << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    this->_hitPoint -= amount;
    std::cout << EXPLOSION << " ClapTrap " << this->_Name << " took " << amount << " damage!";
    if (this->_hitPoint > 0) {
        std::cout << " Health: " << this->_hitPoint << std::endl;
    } else {
        std::cout << " Health: 0" << std::endl; 
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_Energy > 0 && this->_hitPoint > 0) {
        this->_hitPoint += amount;
        this->_Energy--;
        std::cout << HOSPITAL << " ClapTrap " << _Name << " got a reparation kit of " << amount << " hit points. Health: " << this->_hitPoint << std::endl; 
    } else if (this->_Energy <= 0) {
        std::cout << RED << "ClapTrap " << _Name << " can't be repaired... Out of energy." << RESET << std::endl;
    } else {
        std::cout << RED << "ClapTrap " << _Name << " can't be repaired... No more health." << RESET << std::endl;
    }
}