#include "../includes/ScavTrap.hpp"
#include "../includes/ColorCodes.hpp"
#include "../includes/Emojis.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    _hitPoint = 100;
    _Energy = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _Name << " created with default constructor" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    _hitPoint = 100;
    _Energy = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _Name << " created with parameterized constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap " << _Name << " created with copy constructor" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _Name << " destroyed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "ScavTrap " << _Name << " assigned from another ScavTrap" << std::endl;
    return *this;
}

void ScavTrap::attack(const std::string& target) {
    if (_Energy > 0 && _hitPoint > 0) {
        _Energy--;
        std::cout << SWORD SWORD << " ScavTrap " << _Name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
    } else if (_Energy <= 0) {
        std::cout << RED << "ScavTrap " << _Name << " can't attack... Out of energy." << RESET << std::endl;
    } else {
        std::cout << RED << "ScavTrap " << _Name << " can't attack... No more health." << RESET << std::endl;
    }
}

void ScavTrap::guardGate() {
    std::cout << GUARD << " ScavTrap " << _Name << " is in Guard Gate mode." << std::endl;
}