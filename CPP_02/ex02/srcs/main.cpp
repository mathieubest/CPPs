#include "../includes/Fixed.hpp"
#include <iostream>

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    // Test increment operators
    std::cout << "Initial value of a: " << a << std::endl;
    std::cout << "Pre-increment a: " << ++a << std::endl;
    std::cout << "Value of a after pre-increment: " << a << std::endl;
    std::cout << "Post-increment a: " << a++ << std::endl;
    std::cout << "Value of a after post-increment: " << a << std::endl;

    // Test arithmetic operators
    Fixed c(10);
    Fixed d(2);
    std::cout << "c: " << c << ", d: " << d << std::endl;
    std::cout << "c + d: " << (c + d) << std::endl;
    std::cout << "c - d: " << (c - d) << std::endl;
    std::cout << "c * d: " << (c * d) << std::endl;
    std::cout << "c / d: " << (c / d) << std::endl;

    // Test comparison operators
    Fixed e(5.4f);
    Fixed f(10.10f);
    std::cout << "e: " << e << ", f: " << f << std::endl;
    std::cout << "e > f: " << (e > f) << std::endl;
    std::cout << "e < f: " << (e < f) << std::endl;
    std::cout << "e >= f: " << (e >= f) << std::endl;
    std::cout << "e <= f: " << (e <= f) << std::endl;
    std::cout << "e == f: " << (e == f) << std::endl;
    std::cout << "e != f: " << (e != f) << std::endl;

    // Test max function
    std::cout << "Max of a and b: " << Fixed::max( a, b ) << std::endl;
    std::cout << "Min of a and b: " << Fixed::min( a, b ) << std::endl;

    return 0;
}