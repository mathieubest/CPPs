#pragma once
#include <string>

#define BOLD_GREEN "\033[1;32m"
#define BOLD_BLUE "\033[1;34m"
#define BOLD_RED "\033[1;31m"
#define RESET "\033[0m"

class Zombie {
    public:
        Zombie (std::string name);
        ~Zombie (void);
        void announce(void);

    private:
        std::string name;
    
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);
