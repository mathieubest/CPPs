#include "../includes/FragTrap.hpp"
#include "../includes/ColorCodes.hpp"
#include "../includes/Emojis.hpp"

FragTrap::FragTrap() : ClapTrap() {
    _hitPoint = 100;
    _Energy = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _Name << " created with default constructor." << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    this->_hitPoint = 100;
    this->_Energy = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap " << _Name << " created with ." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap " << _Name << " created with copy constructor." << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _Name << " destroyed." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "FragTrap " << _Name << " assigned from another FragTrap" << std::endl;
    return *this;
}

void FragTrap::attack(const std::string& target) {
    if (_Energy > 0 && _hitPoint > 0) {
        _Energy--;
        std::cout << SWORD SWORD << " ScavTrap " << _Name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
    } else if (_Energy <= 0) {
        std::cout << RED << "ScavTrap " << _Name << " can't attack... Out of energy." << RESET << std::endl;
    } else {
        std::cout << RED << "ScavTrap " << _Name << " can't attack... No more health." << RESET << std::endl;
    }
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _Name << " requested a Positive High Five Guys." << std::endl;
}

