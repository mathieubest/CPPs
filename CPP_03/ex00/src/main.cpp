#include "../includes/ClapTrap.hpp"
#include "../includes/ColorCodes.hpp"

int main() {
    std::cout << BOLD_BLUE << "-- Constructing --" << RESET << std::endl;
    ClapTrap def;
    ClapTrap a("Mouss");
    ClapTrap b("Broski");
    ClapTrap copy(b);

    copy = a;

    std::cout << BOLD_BLUE << "-- Testing --" << RESET << std::endl;
    b.takeDamage(10);
    b.attack("Sam");
    b.beRepaired(5);
    
    a.takeDamage(5);
    a.beRepaired(3);
    for (int i = 1; i <= 15; i++) {
        a.attack("Boogie");
    }
    a.beRepaired(5);
    copy.attack("Bad Guy");
    copy.takeDamage(30);
    copy.beRepaired(20);
    std::cout << BOLD_BLUE << "-- Deconstructing --" << RESET << std::endl;
    return (0);
}
