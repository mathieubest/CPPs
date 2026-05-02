#include "../include/Array.tpp"
#include <iostream>

#define BOLD_BLUE "\033[1;34m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

int main() {
    try {
        Array<int> empty;
        std::cout << BOLD_BLUE << "=== Using default constructor ===" << RESET << std::endl;
        std::cout << "Empty array size: " << empty.size() << std::endl;

        std::cout << std::endl << BOLD_BLUE << "=== Using parameterized constructor ===" << RESET << std::endl;
        Array<int> numbers(5);
        std::cout << "Array size: " << numbers.size() << std::endl;
        for (unsigned int i = 0; i < numbers.size(); i++) {
            numbers[i] = i * 2;
        }
        for (unsigned int i = 0; i < numbers.size(); i++) {
            std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
        }

        std::cout << std::endl << BOLD_BLUE << "=== Using copy constructor ===" << RESET << std::endl;
        Array<int> copy(numbers);
        std::cout << "Copy size: " << copy.size() << std::endl;
        for (unsigned int i = 0; i < copy.size(); i++) {
            std::cout << "copy[" << i << "] = " << copy[i] << std::endl;
        }

        std::cout << std::endl << BOLD_BLUE << "=== Modified array without affecting the copy ===" << RESET << std::endl;
        std::cout << "Changing numbers[2] = 100" << std::endl;
        numbers[2] = 100;
        std::cout << "Numbers array[2]: " << numbers[2] << std::endl;
        std::cout << "Copy array[2]: " << copy[2] << std::endl;

        std::cout << std::endl << BOLD_BLUE << "=== Testing to modify an index out of range ===" << RESET << std::endl;
        numbers[10] = 0;
    }
    catch (const std::exception& e) {
        std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << std::endl << BOLD_BLUE << "=== Testing on a const Array ===" << RESET << std::endl;
        const Array<int> constNumbers(5);
        for (unsigned int i = 0; i < constNumbers.size(); i++) {
            std::cout << "constNumbers[" << i << "]" << " = " << constNumbers[i] << std::endl;
        }
        
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << std::endl << GREEN << "=== Testing Float Array ===" << RESET << std::endl;
        Array<float> floats(3);
        floats[0] = 1.1f;
        floats[1] = 2.2f;
        floats[2] = 3.3f;

        std::cout << "Float array elements:" << std::endl;
        for (unsigned int i = 0; i < floats.size(); i++) {
            std::cout << "floats[" << i << "] = " << floats[i] << std::endl;
        }

        std::cout << std::endl << GREEN << "=== Testing Double Array ===" << RESET << std::endl;
        Array<double> doubles(3);
        doubles[0] = 1.111;
        doubles[1] = 2.222;
        doubles[2] = 3.333;

        std::cout << "Double array elements:" << std::endl;
        for (unsigned int i = 0; i < doubles.size(); i++) {
            std::cout << "doubles[" << i << "] = " << doubles[i] << std::endl;
        }

        std::cout << std::endl << GREEN << "=== Testing String Array ===" << RESET << std::endl;
        Array<std::string> strings(4);
        strings[0] = "Hi";
        strings[1] = "How";
        strings[2] = "Are";
        strings[3] = "You";

        std::cout << "String array elements:" << std::endl;
        for (unsigned int i = 0; i < strings.size(); i++) {
            std::cout << "strings[" << i << "] = " << strings[i] << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    return 0;
}
