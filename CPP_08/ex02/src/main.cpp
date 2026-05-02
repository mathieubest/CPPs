#include "../template/MutantStack.tpp"


#define BOLD_BLUE "\033[1;34m"
#define BOLD_YLO "\033[1;33m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

#include <iostream>
#include <stack>
#include <list>
#include <vector>

int main()
{
    {
        MutantStack<int> mstack;
        
        mstack.push(10);
        mstack.push(20);
        mstack.push(30);
        mstack.push(40);
        
        std::cout << BOLD_YLO "== Initial stack ==" RESET << std::endl;
        std::cout << "Top element: " << mstack.top() << std::endl;
        
        mstack.pop();
        std::cout << "After pop, size: " << mstack.size() << std::endl;
        std::cout << "New top: " << mstack.top() << std::endl;
        
        std::cout << "Elements in the stack (LIFO): ";
        for(MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
            std::cout << *rit << " ";
        }
        std::cout << std::endl;

        std::cout << "Elements in the stack (forward): ";
        for(MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
        std::stack<int> s(mstack);
        std::cout << "Element on top of the copied standard stack: " << s.top() << std::endl;
    }

    {
        std::cout << BOLD_YLO << "== Using std::list as container (float) ==" RESET << std::endl;
        MutantStack<float, std::list<float> > mstack;
        
        mstack.push(1.1f);
        mstack.push(2.2f);
        mstack.push(3.3f);
        mstack.push(4.4f);

        std::cout << "Top element: " << mstack.top() << std::endl;
        
        std::cout << "Printing out the stack (LIFO): " << std::endl;
        mstack.print();

        std::cout << "Elements in the stack (forward): ";
        for(MutantStack<float, std::list<float> >::iterator it = mstack.begin(); it != mstack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    
    {
        std::cout << BOLD_YLO << "== Using std::vector as container (char) ==" RESET << std::endl;
        MutantStack<char, std::vector<char> > mstack;
        
        mstack.push('a');
        mstack.push('b');
        mstack.push('c');
        mstack.push('d');

        std::cout << "Top element: " << mstack.top() << std::endl;
        
        std::cout << "Printing out the stack (LIFO): " << std::endl;
        mstack.print();
    
        std::cout << "Elements in the stack (forward): ";
        for(MutantStack<char, std::vector<char> >::iterator it = mstack.begin(); it != mstack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
}