#pragma once
#include "Contact.hpp"
#include <iostream>

class PhoneBook {
    private:
        Contact contacts[8];
        int numOfContacts;
        int currentIndex;

        std::string truncate(const std::string &str) const;

    public:
        PhoneBook();
        ~PhoneBook();

        void addContact(bool& running);
        void displayContacts(bool& running) const;
};
