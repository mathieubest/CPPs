#include "../include/whatever.hpp"

#define BOLD_BLUE "\033[1;34m"
#define GREEN "\033[0;32m"
#define GREY "\033[90m"
#define RESET "\033[0m"

int main( void )
{
    int a = 2;
    int b = 3;
    int c = 3;
    // float f = 2.5f;
    std::string d = "chaine1";
    std::string e = "chaine2";

    std::cout << BOLD_BLUE << "=== Testing the swap function ===" << RESET << std::endl;
    std::cout << "Before Swap:\t" << "a = " << a << ", b = " << b << std::endl;
    ::swap( a, b );
    std::cout << "After Swap:\t" << "a = " << a << ", b = " << b << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    std::cout << "Before Swap:\t" << "d = " << d << ", e = " << e << std::endl;
    ::swap(d, e);
    std::cout << "After Swap:\t" << "d = " << d << ", e = " << e << std::endl;

    std::cout << std::endl << BOLD_BLUE << "=== Testing the min / max functions ===" << RESET << std::endl;
    std::cout << GREEN << "[Testing with ints]" << RESET << std::endl;
    std::cout << GREY << "a = " << a << ", b = " << b << RESET << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::cout << GREY << "a = " << a << ", c = " << c << RESET << std::endl;
    std::cout << "min( a, c ) = " << ::min( a, c ) << std::endl;
    std::cout << "max( a, c ) = " << ::max( a, c ) << std::endl;
    std::cout << GREEN << "[Testing with strings]" << RESET << std::endl;

    std::cout << GREY << "d = " << d << ", e = " << e << RESET << std::endl;
    std::cout << "min( d, e ) = " << ::min( d, e ) << std::endl;
    std::cout << "max( d, e ) = " << ::max( d, e ) << std::endl;

    // std::cout << ::min( a, d ) << std::endl;
    // std::cout << ::min( a, f ) << std::endl;
    return 0;
}
