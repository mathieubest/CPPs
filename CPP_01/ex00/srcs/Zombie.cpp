#include "../includes/Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : name(name) {
    return;
}

Zombie::~Zombie(void) {
    std::cout << BOLD_RED << " Zombie [" << BOLD_BLUE << name << BOLD_RED << "] is destroyed" << RESET << std::endl;
    return;
}

void Zombie::announce(void){
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
