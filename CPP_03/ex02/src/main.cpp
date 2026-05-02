#include "../includes/FragTrap.hpp"
#include "../includes/ColorCodes.hpp"

int main() {
    std::cout << BOLD_BLUE << "-- Constructing --" << RESET << std::endl;
    FragTrap def;
    FragTrap a("Mista");
    FragTrap b("BooBoo");
    b = a;

    std::cout << BOLD_BLUE << "-- Testing --" << RESET << std::endl;
    a.attack("Broski");
    a.attack("Broski");
    a.highFivesGuys();
    a.beRepaired(20);
    a.takeDamage(10);
    for (int i = 0; i < 100; i++) {
        a.attack("Sam");
    }
    a.beRepaired(5);
    std::cout << BOLD_BLUE << "-- Deconstructing --" << RESET << std::endl;
    return (0);
}
