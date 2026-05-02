#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#define DEBUG 1

#include <list>
#include <deque>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <ctime>

template<typename T>
class PmergeMe {
    private:
        T _container;
        std::vector<std::pair<int, int> > _pairs;
        std::vector<int> _jacobsthal;
        int _unpairedElement;

        void generateJacobsthalSequence(size_t size);
        void sortPairs();
        void createPairs();
        void sortPairsInternally();
        void mergeInsertSort();
        void insertUnpairedElement();
        int getNextJacobsthalNumber(int n);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void sort();
        void print();
        void addNumber(int number);
        size_t getSize() const;
};

#endif
