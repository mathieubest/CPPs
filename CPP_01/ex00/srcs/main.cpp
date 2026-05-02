#include "../includes/Zombie.hpp"
#include <iostream>

int main() {

    std::cout << BOLD_GREEN << "This is a stack created Zombie" << RESET << std::endl;
    Zombie stackZombie("Woo");
    stackZombie.announce();
    std::cout << std::endl;

    std::cout << BOLD_GREEN << "This is a heap Zombie" << RESET << std::endl;
    Zombie *heapZombie = newZombie("Foo");
    heapZombie->announce();
    delete heapZombie;
    std::cout << std::endl;

    std::cout << BOLD_GREEN << "Function call to randomChump()" << RESET << std::endl;
    randomChump("Boo");
    std::cout << std::endl;

    return(0);
}