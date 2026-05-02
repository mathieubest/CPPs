#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
// #include <ctime>
#include <cstdlib>

class Span {
    private:
        unsigned int _size;
        std::vector<int> _vec;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span& copy);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int number);
        void shortestSpan();
        void longestSpan();

        void addXNumbers(int x);
        void printVector();
};

#endif