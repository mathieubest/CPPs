#include "../includes/ScavTrap.hpp"
#include "../includes/ColorCodes.hpp"

int main() {
    std::cout << BOLD_BLUE << "-- Constructing --" << RESET << std::endl;
    ScavTrap def;
    ScavTrap a("Tata");
    ScavTrap b("Boba");
    b = a;

    std::cout << BOLD_BLUE << "-- Testing --" << RESET << std::endl;
    a.attack("Toto");
    a.takeDamage(80);
    a.attack("Titi");
    a.guardGate();
    a.beRepaired(20);
    a.takeDamage(39);
    a.beRepaired(9);
    a.takeDamage(10);
    a.beRepaired(50);
    std::cout << BOLD_BLUE << "-- Deconstructing --" << RESET << std::endl;
    return (0);
}
