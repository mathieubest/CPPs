#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <exception>

Base* generate() {
    int random = rand() % 3;
    switch (random) {
        case(0):
            return new A();
        case(1):
            return new B();
        case(2):
            return new C();
        default:
            return NULL;
    }
}

void identify(Base* p) {
    A* a = dynamic_cast<A*>(p);
    if (a != NULL) {
        std::cout << "A" << std::endl;
        return;
    }
    
    B* b = dynamic_cast<B*>(p);
    if (b != NULL) {
        std::cout << "B" << std::endl;
        return;
    }

    C* c = dynamic_cast<C*>(p);
    if (c != NULL) {
        std::cout << "C" << std::endl;
        return;
    }
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception& e) {}

    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception& e) {}

    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    } catch (std::exception& e) {}
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    {
        std::cout << GREEN "Test 1" RESET << std::endl;
        Base* p = generate();
        identify(p);
        identify(*p);
        delete p;
    }

    {
        std::cout << GREEN "Test 2" RESET << std::endl;
        Base* p = generate();
        identify(p);
        identify(*p);
        delete p;
    }

    {
        std::cout << GREEN "Test 3" RESET << std::endl;
        Base* p = generate();
        identify(p);
        identify(*p);
        delete p;
    }

    return 0;
}
