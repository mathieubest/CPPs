#include "../include/BitcoinExchange.hpp"

#include <sstream>
#include <stdexcept>

int main(int ac, char** av) {
    if (ac != 2) {
        std::cerr << "Usage: ./btc <input.txt>" << std::endl;
        return (1);
    }

    try {
        BitcoinExchange map;
        map.readcsv("data.csv");
        map.parsecsv(map.buff);
        if (!map.checkInput(av[1])) {
            return (1);
        }
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }

    return 0;
}
