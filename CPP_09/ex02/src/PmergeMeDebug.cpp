#include "../include/PmergeMe.hpp"
#include <iostream>
#include <utility>
#include <algorithm>

template<typename T>
PmergeMe<T>::PmergeMe() : _unpairedElement(-1) {
    _container = T();
    _pairs = std::vector<std::pair<int, int> >();
    _jacobsthal = std::vector<int>();
}

template<typename T>
PmergeMe<T>::PmergeMe(const PmergeMe &copy) {
    _container = copy._container;
    _pairs = copy._pairs;
    _jacobsthal = copy._jacobsthal;
    _unpairedElement = copy._unpairedElement;
}

template<typename T>
PmergeMe<T> &PmergeMe<T>::operator=(const PmergeMe &other) {
    if (this != &other) {
        _container = other._container;
        _pairs = other._pairs;
        _jacobsthal = other._jacobsthal;
        _unpairedElement = other._unpairedElement;
    }
    return *this;
}

template<typename T>
PmergeMe<T>::~PmergeMe() {
    _container.clear();
    _pairs.clear();
    _jacobsthal.clear();
}

//# Private methods
template<typename T>
int PmergeMe<T>::getNextJacobsthalNumber(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return getNextJacobsthalNumber(n - 1) + 2 * getNextJacobsthalNumber(n - 2);
}

template<typename T>
void PmergeMe<T>::generateJacobsthalSequence(size_t size) {
    int i = 0;
    int jacob = getNextJacobsthalNumber(i);
    while (jacob < static_cast<int>(size)) {
        _jacobsthal.push_back(jacob);
        i++;
        jacob = getNextJacobsthalNumber(i);
    }
}

template<typename T>
void PmergeMe<T>::mergeInsertSort() {
    _container.clear();
    // Insert the first pair
    if (!_pairs.empty()) {
        _container.push_back(_pairs[0].first);
        _container.push_back(_pairs[0].second);
        if (DEBUG) {
            std::cout << "  a) Inserting first pair: " << _pairs[0].first << ", " << _pairs[0].second << std::endl;
        }
    }

    // Generate Jacobsthal sequence
    generateJacobsthalSequence(_pairs.size());
    if (DEBUG) {
        std::cout << "  b) Generated Jacobsthal sequence for optimal insertion order: ";
        for (size_t i = 0; i < _jacobsthal.size(); i++) {
            std::cout << _jacobsthal[i] << " ";
        }
        std::cout << std::endl;
    }

    // Insert remaining elements using Jacobsthal sequence
    std::vector<bool> inserted(_pairs.size(), false);
    inserted[0] = true;  // First pair is already inserted

    if (DEBUG) {
        std::cout << "  c) Inserting all second elements (they're already sorted):" << std::endl;
    }
    // First insert all second elements (they're already sorted)
    for (size_t i = 1; i < _pairs.size(); i++) {
        typename T::iterator it = std::lower_bound(_container.begin(), _container.end(), _pairs[i].second);
        _container.insert(it, _pairs[i].second);
        if (DEBUG) {
            std::cout << "     Inserted: " << _pairs[i].second << std::endl;
        }
    }

    if (DEBUG) {
        std::cout << "  d) Inserting first elements using Jacobsthal sequence:" << std::endl;
        std::cout << "     Current container: ";
        for (typename T::iterator it = _container.begin(); it != _container.end(); it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    // Then insert first elements using Jacobsthal sequence
    for (size_t i = 1; i < _jacobsthal.size(); i++) {
        int current = _jacobsthal[i];
        int previous = _jacobsthal[i - 1];

        // Insert the current Jacobsthal number's element
        if (current < static_cast<int>(_pairs.size()) && !inserted[current]) {
            std::cout << "     Jacobsthal index " << current << " -> Inserting first element of pair "
                     << current << ": " << _pairs[current].first << std::endl;
            typename T::iterator it = std::lower_bound(_container.begin(), _container.end(), _pairs[current].first);
            _container.insert(it, _pairs[current].first);
            inserted[current] = true;
            std::cout << "     Container after insertion: ";
            for (typename T::iterator it = _container.begin(); it != _container.end(); it++) {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }

        // Insert elements in reverse order from previous to current
        for (int j = current - 1; j > previous; j--) {
            if (j < static_cast<int>(_pairs.size()) && !inserted[j]) {
                std::cout << "     Inserting in reverse order, index " << j << " -> Inserting first element of pair "
                         << j << ": " << _pairs[j].first << std::endl;
                typename T::iterator it = std::lower_bound(_container.begin(), _container.end(), _pairs[j].first);
                _container.insert(it, _pairs[j].first);
                inserted[j] = true;
                std::cout << "     Container after insertion: ";
                for (typename T::iterator it = _container.begin(); it != _container.end(); it++) {
                    std::cout << *it << " ";
                }
                std::cout << std::endl;
            }
        }
    }

    std::cout << "  e) Inserting any remaining first elements:" << std::endl;
    std::cout << "     Current container: ";
    for (typename T::iterator it = _container.begin(); it != _container.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Insert any remaining first elements
    for (size_t i = 1; i < _pairs.size(); i++) {
        if (!inserted[i]) {
            std::cout << "     Inserting remaining first element of pair " << i << ": " << _pairs[i].first << std::endl;
            typename T::iterator it = std::lower_bound(_container.begin(), _container.end(), _pairs[i].first);
            _container.insert(it, _pairs[i].first);
            std::cout << "     Container after insertion: ";
            for (typename T::iterator it = _container.begin(); it != _container.end(); it++) {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }
    }
}

template<typename T>
void PmergeMe<T>::insertUnpairedElement() {
    if (_unpairedElement != -1) {
        typename T::iterator it = std::lower_bound(_container.begin(), _container.end(), _unpairedElement);
        _container.insert(it, _unpairedElement);
    }
}

template<typename T>
void PmergeMe<T>::createPairs() {
    typename T::iterator it = _container.begin();
    if (DEBUG) {
        std::cout << "\nStep 2: Creating pairs of elements:" << std::endl;
    }
    while (it != _container.end()) {
        int first = *it++;
        if (it != _container.end()) {
            int second = *it++;
            _pairs.push_back(std::make_pair(first, second));
            if (DEBUG) {
                std::cout << "  Created pair: (" << first << ", " << second << ")" << std::endl;
            }
        }
    }
}

template<typename T>
void PmergeMe<T>::sortPairsInternally() {
    if (DEBUG) {
        std::cout << "\nStep 3: Sorting each pair internally:" << std::endl;
    }
    for (size_t i = 0; i < _pairs.size(); i++) {
        if (DEBUG) {
            std::cout <<"(" << _pairs[i].first << "," << _pairs[i].second << ")";
        }
        if (_pairs[i].first > _pairs[i].second) {
            std::swap(_pairs[i].first, _pairs[i].second);
            if (DEBUG) {
                std::cout << " -> After: (" << _pairs[i].first << ", " << _pairs[i].second << ")" << std::endl;
            }
        } else {
            if (DEBUG) {
                std::cout << " (already sorted)" << std::endl;
            }
        }
    }
}

template<typename T>
void PmergeMe<T>::sortPairs() {
    if (DEBUG) {
        std::cout << "\nStep 4: Sorting pairs based on their larger elements:" << std::endl;
    }
    for (size_t i = 0; i < _pairs.size(); i++) {
        for (size_t j = i + 1; j < _pairs.size(); j++) {
            if (_pairs[i].second > _pairs[j].second) {
                std::swap(_pairs[i], _pairs[j]);
                if (DEBUG) {
                    std::cout << "  Swapped pairs: (" << _pairs[i].first << ", " << _pairs[i].second
                             << ") <-> (" << _pairs[j].first << ", " << _pairs[j].second << ")" << std::endl;
                }
            }
        }
    }
}

//# Public methods
template<typename T>
void PmergeMe<T>::sort() {
    if (DEBUG) {
        std::cout << "\n=== Starting Ford-Johnson Merge-Insert Sort ===" << std::endl;
    }

    // Handle odd number of elements
    if (_container.size() % 2) {
        _unpairedElement = _container.back();
        if (DEBUG) {
            std::cout << "Step 1: Found unpaired element (odd element): " << _unpairedElement << std::endl;
        }
        _container.pop_back();
    }

    // Special case: only one element (unpairedElement)
    if (_container.empty() && _unpairedElement != -1) {
        insertUnpairedElement();
        return;
    }

    createPairs();
    sortPairsInternally();
    sortPairs();

    if (DEBUG) {
        std::cout << "\nFinal sorted pairs (by larger element):" << std::endl;
        for (size_t i = 0; i < _pairs.size(); i++) {
            std::cout << "  Pair " << i << ": (" << _pairs[i].first << ", " << _pairs[i].second << ")" << std::endl;
        }
    }

    // Perform merge-insert sort
    std::cout << "\nStep 5: Starting merge-insert sort" << std::endl;
    mergeInsertSort();

    // Insert unpairedElement if exists
    if (_unpairedElement != -1) {
        std::cout << "\nStep 6: Inserting unpaired element: " << _unpairedElement << std::endl;
    }
    insertUnpairedElement();
}

template<typename T>
void PmergeMe<T>::print() {
    for (typename T::iterator it = _container.begin(); it != _container.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void PmergeMe<T>::addNumber(int number) {
    _container.push_back(number);
}

template<typename T>
size_t PmergeMe<T>::getSize() const {
    return _container.size();
}
