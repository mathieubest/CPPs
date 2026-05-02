#include "../includes/Zombie.hpp"
#include <iostream>

Zombie* newZombie(std::string name) {
    return new Zombie(name);
}
