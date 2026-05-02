#include "../includes/Point.hpp"

int main() {
    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(0.0f, 3.0f);

    Point inside(1.0f, 1.0f);
    Point outside(5.0f, 5.0f);

    std::cout << "Inside: " << bsp(a, b, c, inside) << std::endl;
    std::cout << "Outside: " << bsp(a, b, c, outside) << std::endl;

    return 0;
}