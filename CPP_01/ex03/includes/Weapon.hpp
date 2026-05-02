#pragma once
#include <string>

class Weapon {
    public:
        Weapon(std::string type);
        ~Weapon(void);
        const std::string& getType(void);
        void setType(const std::string &type);

    private:
        std::string type;
};
