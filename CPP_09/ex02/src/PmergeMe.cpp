#include "../include/PmergeMe.hpp"

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
    if (!_pairs.empty()) {
        _container.push_back(_pairs[0].first);
        _container.push_back(_pairs[0].second);
    }
    generateJacobsthalSequence(_pairs.size());

    std::vector<bool> inserted(_pairs.size(), false);
    inserted[0] = true;

    for (size_t i = 1; i < _pairs.size(); i++) {
        typename T::iterator it = std::lower_bound(_container.begin(), _container.end(), _pairs[i].second);
        _container.insert(it, _pairs[i].second);
    }

    for (size_t i = 1; i < _jacobsthal.size(); i++) {
        int current = _jacobsthal[i];
        int previous = _jacobsthal[i - 1];

        if (current < static_cast<int>(_pairs.size()) && !inserted[current]) {
            typename T::iterator it = std::lower_bound(_container.begin(), _container.end(), _pairs[current].first);
            _container.insert(it, _pairs[current].first);
            inserted[current] = true;
        }

        for (int j = current - 1; j > previous; j--) {
            if (j < static_cast<int>(_pairs.size()) && !inserted[j]) {
                typename T::iterator it = std::lower_bound(_container.begin(), _container.end(), _pairs[j].first);
                _container.insert(it, _pairs[j].first);
                inserted[j] = true;
            }
        }
    }

    for (size_t i = 1; i < _pairs.size(); i++) {
        if (!inserted[i]) {
            typename T::iterator it = std::lower_bound(_container.begin(), _container.end(), _pairs[i].first);
            _container.insert(it, _pairs[i].first);
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
    while (it != _container.end()) {
        int first = *it++;
        if (it != _container.end()) {
            int second = *it++;
            _pairs.push_back(std::make_pair(first, second));
        }
    }
}

template<typename T>
void PmergeMe<T>::sortPairsInternally() {
    for (size_t i = 0; i < _pairs.size(); i++) {
        if (_pairs[i].first > _pairs[i].second) {
            std::swap(_pairs[i].first, _pairs[i].second);
        }
    }
}

template<typename T>
void PmergeMe<T>::sortPairs() {
    for (size_t i = 0; i < _pairs.size(); i++) {
        for (size_t j = i + 1; j < _pairs.size(); j++) {
            if (_pairs[i].second > _pairs[j].second) {
                std::swap(_pairs[i], _pairs[j]);
            }
        }
    }
}

template<typename T>
void PmergeMe<T>::sort() {
    if (_container.size() % 2) {
        _unpairedElement = _container.back();
        _container.pop_back();
    }

    if (_container.empty() && _unpairedElement != -1) {
        insertUnpairedElement();
        return;
    }

    createPairs();
    sortPairsInternally();
    sortPairs();
    mergeInsertSort();
    if (_unpairedElement != -1) {
        insertUnpairedElement();
    }
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

// Explicit template instantiation
template class PmergeMe<std::list<int> >;
template class PmergeMe<std::deque<int> >;
