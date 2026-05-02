#pragma once
#include "Weapon.hpp"
#include <string>

class HumanB {
    public:
        HumanB(std::string name);
        ~HumanB(void);
        void attack(void);
        void setWeapon(Weapon& weapon);

    private:
        std::string name;
        Weapon* weapon;
};