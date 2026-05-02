#include "../includes/HumanA.hpp"
#include <string>
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {
    return;
}

HumanA::~HumanA(void) {
    return;
}

void HumanA::attack(void) {
    std::cout << this->name << " has attacked with " << weapon.getType() << std::endl;
}
