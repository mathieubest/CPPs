#include <iostream>
#include <cctype>
#include <string>

int main(int ac, char **av)
{
    if (ac < 2) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return(1);
    }

    for (int i = 1; i < ac; i++) {
        std::string str(av[i]);
        for (std::string::iterator it = str.begin(); it != str.end(); it++) {
            std::cout << static_cast<char>(std::toupper(*it));
        }
    }
    std::cout << std::endl;

    return(0);
}
