#include "../includes/HumanB.hpp"
#include <string>
#include <iostream>

HumanB::HumanB(std::string name) : name(name) {
    return;
}

HumanB::~HumanB(void) {
    return;
}

void HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
}

void HumanB::attack(void) {
    if (weapon) {
        std::cout << this->name << " has attacked with " << weapon->getType() << std::endl;
    } else {
        std::cout << this->name << " has no weapon." << std::endl;
    }
}
