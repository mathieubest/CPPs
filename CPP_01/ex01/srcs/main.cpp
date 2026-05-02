#include "../includes/Zombie.hpp"
#include <iostream>
#include <iomanip>

int main() {
    int N = NUM_OF_ZOMBIES;

    Zombie* horde = zombieHorde(N, "Zoo");
    for(int i = 0; i < N; i++) {
        std::cout << std::setw(2) << std::left << i + 1 << ": ";
        horde[i].announce();
    }

    delete[] horde;
    return (0);
}
