#include "../include/PmergeMe.hpp"

static int parsing(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        for (int j = 0; argv[i][j]; j++) {
            if (!std::isdigit(argv[i][j])) {
                std::cout << "Error: " << argv[i] << " is not a valid positive integer" << std::endl;
                return 0;
            }
        }
        if (std::strlen(argv[i]) > 10) {
            std::cout << "Error: " << argv[i] << " is too long" << std::endl;
            return 0;
        }
        if (strtol(argv[i], NULL, 10) < 0 || strtol(argv[i], NULL, 10) > INT_MAX) {
            std::cout << "Error: " << argv[i] << " is out of range" << std::endl;
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Usage:\t ./PmergeMe [number list]" << std::endl;
        std::cout << "Example: ./PmergeMe 1 4 2 67 45" << std::endl;
        return 1;
    }

    if (!parsing(argc, argv)) {
        return 1;
    }

    PmergeMe<std::list<int> > listSorter;
    PmergeMe<std::deque<int> > dequeSorter;

    for (int i = 1; i < argc; i++) {
        int num = atoi(argv[i]);
        listSorter.addNumber(num);
        dequeSorter.addNumber(num);
    }

    std::cout << "Before: ";
    for (int i = 1; i < argc; i++) {
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;

    clock_t start = clock();
    dequeSorter.sort();
    clock_t end = clock();
    double dequeTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After : ";
    dequeSorter.print();
    std::cout << "Time to process a range of " << dequeSorter.getSize() << " elements with std::deque: "
              << dequeTime << "us" << std::endl;

    start = clock();
    listSorter.sort();
    end = clock();
    double listTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << listSorter.getSize() << " elements with std::list: "
              << listTime << "us" << std::endl;

    return 0;
}
