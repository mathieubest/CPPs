#include <iostream>
#include <string>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;
    
    std::cout << "Address of str is: " << &str << std::endl;
    std::cout << "The value of str is: " << str << std::endl << std::endl;

    std::cout << "Address of stringPTR is: " << stringPTR << std::endl;
    std::cout << "The value pointed by stringPTR is: " << *stringPTR << std::endl<<std::endl;

    std::cout << "Address of stringREF is: " << &stringREF << std::endl;
    std::cout << "The value pointed by stringREF is: " << stringREF << std::endl;

    return (0);
}