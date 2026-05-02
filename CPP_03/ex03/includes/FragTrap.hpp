#pragma once

#include "./ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
    public:
        // Constructors
        FragTrap();
        FragTrap(const std::string& name);
        FragTrap(const FragTrap& other);

        // Destructors
        ~FragTrap();

        // Public methods
        void attack(const std::string& target);
        void highFivesGuys(void);

        // Overloaded operator
        FragTrap& operator=(const FragTrap& other);
};