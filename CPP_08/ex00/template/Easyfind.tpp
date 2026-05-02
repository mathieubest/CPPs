#include "../include/Easyfind.hpp"

template <typename T>
int easyfind(T &container, int find) {
    typename T::iterator it = std::find(container.begin(), container.end(), find);
    if (it == container.end()) {
        throw std::runtime_error(RED "Value not found" RESET);
    }
    return *it;
}
