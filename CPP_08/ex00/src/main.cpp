#include "../template/Easyfind.tpp"

#define BOLD_BLUE "\033[1;34m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

#include <list>
#include <vector>
#include <deque>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    std::vector<int> vec(arr, arr + 3);
    std::deque<int> deq(arr, arr + 5);
    std::list<int> lst;
    std::vector<int>::iterator it;
    for (it = vec.begin(); it != vec.end(); it++) {
        lst.push_back(*it * 2);
    }

    //#Printing out the containers
    std::cout << std::endl << BOLD_BLUE << "=== Printing out the containers ===" << RESET << std::endl;
    std::cout << GREEN << "Vector:\t" RESET;
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    std::cout << GREEN << "Deque:\t" RESET;
    for (size_t i = 0; i < deq.size(); i++) {
        std::cout << deq[i] << " ";
    }
    std::cout << std::endl;

    std::cout << GREEN << "List:\t" RESET;
    for(std::list<int>::iterator lit = lst.begin(); lit != lst.end(); lit++) {
        std::cout << *lit << " ";
    }
    std::cout << std::endl;

    //# Test 1
    try {
        std::cout << std::endl << BOLD_BLUE << "=== Searching 3 in the vector, 4 in the deque and 6 in the list ===" << RESET << std::endl;
        int resultVec = easyfind(vec, 3);
        std::cout << "Found " << resultVec << " in the vector." << std::endl;
        int resultDeq = easyfind(deq, 4);
        std::cout << "Found " << resultDeq << " in the deque." << std::endl;
        int resultLst = easyfind(lst, 6);
        std::cout << "Found " << resultLst << " in the list." << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Runtime error: " << e.what() << std::endl;
    }

    //# Test 2
    try {
        std::cout << std::endl << BOLD_BLUE << "=== Searching 14 in the list ===" << RESET << std::endl;
        int result = easyfind(lst, 14);
        std::cout << "Found " << result << " in the list." << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Runtine error: " << e.what() << std::endl;
    }
    return (0);
}