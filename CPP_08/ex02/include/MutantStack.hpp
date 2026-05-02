#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>{
    public:

        MutantStack();
        MutantStack(const MutantStack& copy);
        MutantStack& operator=(const MutantStack &other);
        virtual ~MutantStack();

        typedef typename Container::iterator iterator;
        typedef typename Container::reverse_iterator reverse_iterator;

        iterator begin();
        iterator end();
        reverse_iterator rbegin();
        reverse_iterator rend();

        void print();
};

#endif