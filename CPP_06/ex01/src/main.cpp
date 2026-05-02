#include "../include/Serializer.hpp"

int main() {
    Data data;
    data.a = 42;
    data.b = 84;

    std::cout << BLUE "Original Data: a = " << data.a << ", b = " << data.b << RESET << std::endl;

    std::cout << std::endl << GREEN "Serializing the address of Data to an unsigned int" RESET << std::endl;
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized raw value: " << raw << std::endl;
    std::cout << "Recasting the value of raw to an int" << std::endl;
    std::cout << "First int in raw: " << * reinterpret_cast<int*>(raw) << std::endl;
    std::cout << "Second int in raw: " << * reinterpret_cast<int*>(raw+4) << std::endl;

    std::cout << std::endl << GREEN "Deserializing the raw value into a pointer to Data" RESET << std::endl;
    Data* newData = Serializer::deserialize(raw);
    std::cout << "Deserialized Data: a = " << newData->a << ", b = " << newData->b << std::endl;

    return 0;
}