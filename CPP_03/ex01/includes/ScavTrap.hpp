#pragma once

#include "./ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        // Constructors
        ScavTrap();
        ScavTrap(const std::string& name);
        ScavTrap(const ScavTrap& other);

        // Destructors
        ~ScavTrap();

        // Public methods
        void attack(const std::string& target);
        void guardGate();

        // Overloaded operator
        ScavTrap& operator=(const ScavTrap& other);
};