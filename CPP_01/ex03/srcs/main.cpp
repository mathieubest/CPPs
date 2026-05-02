#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"
#include "../includes/Weapon.hpp"

int main() {
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        // HumanA bob("Bob", club);
        bob.attack();
        club.setType("Wooden club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");

        HumanB joe("Joe");
        joe.attack();
        joe.setWeapon(club);
        joe.attack();
        club.setType("Baseball bat");
        joe.attack();
    }
}