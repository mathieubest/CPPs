#include "../includes/Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type) : type(type) {
    return;
}

Weapon::~Weapon(void) {
    return;
}

const std::string& Weapon::getType(void) {
    return this->type;
}

void Weapon::setType(const std::string &type) {
    this->type = type;
}
