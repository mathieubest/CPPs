#include "../includes/DiamondTrap.hpp"
#include "../includes/ColorCodes.hpp"

int main() {

    std::cout << BOLD_BLUE << "-- Constructing --" << RESET << std::endl;
	DiamondTrap a;
	DiamondTrap b("Bobby");
	DiamondTrap c(a);

    std::cout << BOLD_BLUE << "-- Testing --" << RESET << std::endl;
	a.whoAmI();
	a.attack("Jack");
	b.whoAmI();
	b.attack("Tommy");
	c.whoAmI();

    std::cout << BOLD_BLUE << "-- Deconstructing --" << RESET << std::endl;
    return (0);
}
