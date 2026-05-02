#include "../includes/PhoneBook.hpp"
#include <iostream>
#include <iomanip>

int main() {
    PhoneBook phoneBook;
    std::string command;
    bool running = true;

    while (running) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command)) {
            std::cout << std::endl;
            running = false;
        }
        if (running && command == "ADD") {
            phoneBook.addContact(running);
        } else if (running && command == "SEARCH") {
            phoneBook.displayContacts(running);
        } else if (running && command == "EXIT") {
            running = false;
        } else if (running) {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }
    return 0;
}
