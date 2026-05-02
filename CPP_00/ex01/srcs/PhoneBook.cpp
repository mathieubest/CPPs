#include "../includes/PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

#define BOLD_BLUE "\033[1;34m"
#define RESET "\033[0m"

PhoneBook::PhoneBook() : numOfContacts(0), currentIndex(0) {
    return;
}

PhoneBook::~PhoneBook() {
    return;
}

std::string PhoneBook::truncate(const std::string &str) const {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

void PhoneBook::addContact(bool& running) {
    Contact newContact;
    std::string input;

    do {
        std::cout << "Enter first name: ";
        if (!std::getline(std::cin, input)) {
            std::cout << std::endl;
            running = false;
            return;
        }
    } while (input.empty());
    newContact.setFirstName(input);

    do {
        std::cout << "Enter last name: ";
        if (!std::getline(std::cin, input)) {
            std::cout << std::endl;
            running = false;
            return;
        }
    } while (input.empty());
    newContact.setLastName(input);

    do {
        std::cout << "Enter nickname: ";
        if (!std::getline(std::cin, input)) {
            std::cout << std::endl;
            running = false;
            return;
        }
    } while (input.empty());
    newContact.setNickname(input);

    do {
        std::cout << "Enter phone number: ";
        if (!std::getline(std::cin, input)) {
            std::cout << std::endl;
            running = false;
            return;
        }
        bool valid = true;
        for (std::string::iterator it = input.begin(); it != input.end(); it++) {
            if (!isdigit(*it) && *it != '+' && *it != '-') {
                valid = false;
                break;
            }
        }
        if (!valid) {
            std::cout << "Invalid input. Please enter only numbers or +/- sign" << std::endl;
            input.clear();
        }
    } while (input.empty());
    newContact.setPhoneNumber(input);

    do {
        std::cout << "Enter darkest secret: ";
        if (!std::getline(std::cin, input)) {
            std::cout << std::endl;
            running = false;
            return;
        }
    } while (input.empty());
    newContact.setDarkestSecret(input);

    std::cout << "Current Index: " << currentIndex << std::endl;
    contacts[currentIndex] = newContact;
    currentIndex = (currentIndex + 1) % 8;
    if (numOfContacts < 8) {
        numOfContacts++;
    }
}

void PhoneBook::displayContacts(bool& running)const {
    std::string indexStr;
    int index;
    const std::string bold_on = "\033[1m";
    const std::string bold_off = "\033[0m";
    // Header
    std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << std::endl;
    std::cout << "┃" 
            << BOLD_BLUE << std::setw(10) << std::right << "Index" << RESET << "|"
            << BOLD_BLUE << std::setw(10) << std::right << "First Name" << RESET << "|"
            << BOLD_BLUE << std::setw(10) << std::right << "Last Name" << RESET << "|"
            << BOLD_BLUE << std::setw(10) << std::right << "Nickname" << RESET << "┃" << std::endl;
    if (numOfContacts) {
        std::cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << std::endl;
    } else {
        std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << std::endl;
    }
    for (int i = 0; i < numOfContacts; i++) {
        std::cout << "┃"
                << std::setw(10) << std::right << i + 1 << "|" 
                << std::setw(10) << std::right << truncate(contacts[i].getFirstName()) << "|"
                << std::setw(10) << std::right << truncate(contacts[i].getLastName()) << "|"
                << std::setw(10) << std::right << truncate(contacts[i].getNickname()) << "┃" << std::endl;
                if (i != numOfContacts - 1) {
                    std::cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << std::endl;
                } else {
                    std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << std::endl;
                }
    }
    std::cout << "Enter the index of the contact: ";
    if (!std::getline(std::cin, indexStr)) {
        std::cout << std::endl;
        running = false;
        return;
    }
    std::stringstream ss(indexStr);
    if (ss >> index) {
        if (index > 0 && index <= numOfContacts) {
            const Contact &contact = contacts[index - 1];
            std::cout << std::endl;
            std::cout << std::setw(19) << std::left << "┃ First Name" << ": " << contact.getFirstName() << std::endl;
            std::cout << std::setw(19) << std::left << "┃ Last Name" << ": " << contact.getLastName() << std::endl;
            std::cout << std::setw(19) << std::left << "┃ Nickname" << ": " << contact.getNickname() << std::endl;
            std::cout << std::setw(19) << std::left << "┃ Phone Number" << ": " << contact.getPhoneNumber() << std::endl;
            std::cout << std::setw(19) << std::left << "┃ Dark Secret" << ": " << contact.getDarkestSecret() << std::endl;
            std::cout << std::endl;
        } else {
            std::cout << "Index is out of range..." << std::endl;
        }
    } else {
        std::cout << "You didn't enter a number..." << std::endl;
    }
}