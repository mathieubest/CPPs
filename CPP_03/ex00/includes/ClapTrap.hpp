#pragma once

#include <iostream>
#include <string.h>

class ClapTrap {
    private:
        std::string _Name;
        int _hitPoint;
        int _Energy;
        int _attackDamage;

    public:
        // Constructors
        ClapTrap();
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap& other);
        
        // Destructors
        ~ClapTrap();

        // Public Methods
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        // Overload
        ClapTrap& operator=(const ClapTrap& other);
};