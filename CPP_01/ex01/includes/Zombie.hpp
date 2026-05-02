#pragma once
#include <string>

#define BOLD_GREEN "\033[1;32m"
#define BOLD_BLUE "\033[1;34m"
#define BOLD_RED "\033[1;31m"
#define RESET "\033[0m"

#define NUM_OF_ZOMBIES 10

class Zombie {
    public:
        Zombie(void);
        Zombie (std::string name);
        ~Zombie (void);
        void announce(void);
        void setName(std::string name);

    private:
        std::string name;
};

Zombie *zombieHorde(int N, std::string name);