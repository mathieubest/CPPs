#include "../include/iter.hpp"

#define BOLD_BLUE "\033[1;34m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

template <typename T>
void print(T &n) {
    std::cout << n << " ";
}

template <typename T>
void addOne(T &n) {
    n += 1;
}

void toUpperCase(std::string &str) {
    for (size_t i = 0; i < str.length(); ++i) {
        str[i] = std::toupper(str[i]);
    }
}

int main() {
    std::cout << BOLD_BLUE << "=== Testing int array ===" << RESET << std::endl;
    {
        int array[] = {1, 2, 3, 4, 5};
        std::cout << GREEN << "Original array:" << RESET << std::endl;
        ::iter(array, 5, &print);
        std::cout << std::endl << GREEN << "Adding one to each element:" << RESET << std::endl;
        ::iter(array, 5, &addOne);
        ::iter(array, 5, &print);
    }

    std::cout << std::endl << std::endl << BOLD_BLUE << "=== Testing char array ===" << RESET << std::endl;
    {
        char array2[] = {'a', 'b', 'c', 'd', 'e'};
        std::cout << GREEN << "Original array:" << RESET << std::endl;
        ::iter(array2, 5, &print);
        std::cout << std::endl << GREEN << "Adding one to each element:" << RESET << std::endl;
        ::iter(array2, 5, &addOne);
        ::iter(array2, 5, &print);
    }

    std::cout << std::endl << std::endl << BOLD_BLUE << "=== Testing string array ===" << RESET << std::endl;
    {
        std::string array3[] = {"Hello", "World", "!"};
        std::cout << GREEN << "Original array:" << RESET << std::endl;
        ::iter(array3, 3, &print);
        std::cout << std::endl << GREEN << "Converting to uppercase:" << RESET << std::endl;
        ::iter(array3, 3, &toUpperCase);
        ::iter(array3, 3, &print);
        std::cout << std::endl;
    }
    
    return 0;
}
