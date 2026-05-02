#include "../include/Span.hpp"

Span::Span() : _size(0) {}

Span::Span(unsigned int N) : _size(N) {
    _vec.reserve(N);
}

Span::Span(const Span& copy) : _size(copy._size) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _size = other._size;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(const int number) {
    if (_vec.size() < _size) {
        _vec.push_back(number);
    } else {
        throw std::runtime_error("No more place to stock numbers");
    }
}

void Span::shortestSpan() {
    if (_vec.size() < 2) {
        throw std::runtime_error("Only one number in the vector");
    }
    std::vector<int> sortedVec(_vec);
    std::sort(sortedVec.begin(), sortedVec.end());
    int shortestSpan = sortedVec[1] - sortedVec[0];
    for(size_t i = 1; i < sortedVec.size() - 1; i++) {
        int currentSpan = sortedVec[i + 1] - sortedVec[i];
        if(currentSpan < shortestSpan) {
            shortestSpan = currentSpan;
        }
    }
    std::cout << "Shortest Span:\t" << shortestSpan << std::endl;
}

void Span::longestSpan() {
    if (_vec.size() < 2) {
        throw std::runtime_error("Only one number in the vector");
    }
    int min = *std::min_element(_vec.begin(), _vec.end());
    int max = *std::max_element(_vec.begin(), _vec.end());
    int longestSpan = max - min;
    std::cout << "Longest Span:\t" << longestSpan << std::endl;
}

void Span::addXNumbers(int x) {
    srand((unsigned)time(0));
    int randNum;
    for (int i = 0; i < x; i++) {
        randNum = (rand()%1000)+1;
        addNumber(randNum);
    }
}

void Span::printVector() {
    for(size_t i = 0; i < _vec.size(); i++) {
        std::cout << _vec[i] << " ";
    }
    std::cout << std::endl;
}