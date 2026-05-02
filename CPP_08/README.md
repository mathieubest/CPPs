# C++ Containers and Iterators

This project illustrates the usage of various STL containers and their properties. Below you can find an explanation of three main container types: `std::vector`, `std::deque`, and `std::list`, along with a comparative recap and a note on iterators.

## Containers Description

### std::vector

- **Dynamic Array:** A container that resizes automatically when adding or removing elements.
- **Random Access:** Provides constant time random access (you can quickly access any element via its index).
- **Contiguous Memory:** Elements are stored in contiguous memory, which optimizes cache usage and speeds up traversal.
- **Insertion/Deletion Costs:** Efficient only at the end. Inserting or removing elements elsewhere is expensive because subsequent elements need to be moved.
- **Usage:** It is the most popular sequential container and is recommended by default when a flexible, fast-access array is needed.

#### Example Usage of std::vector
````cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    // Adding elements
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    // Accessing elements via random access
    std::cout << "Element at index 0: " << vec[0] << std::endl;

    // Iterating through all elements
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
````

### std::deque (Double-Ended Queue)

- **Double-Ended Structure:** Allows efficient insertion and removal at both the beginning and the end.
- **Random Access:** Offers random access similar to `std::vector`, albeit the elements are stored in contiguous segments rather than a single block.
- **Flexibility:** More flexible than `std::vector` for both head and tail operations, but with slightly less optimal memory access performance due to segmentation.
- **Iterator Validity:** Iterators may be invalidated more easily compared to those of a `std::list`.
- **Usage:** Useful when fast access and additions/removals at both ends are required.

#### Example Usage of std::deque
````cpp
#include <iostream>
#include <deque>

int main() {
    std::deque<int> deq;

    // Insert elements at both ends
    deq.push_back(10);
    deq.push_front(20);
    deq.push_back(30);

    // Random access similar to vector
    std::cout << "Element at index 1: " << deq[1] << std::endl;

    // Iteration over the deque
    for (size_t i = 0; i < deq.size(); i++) {
        std::cout << deq[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
````

### std::list

- **Doubly-Linked List:** Each element points to the previous and next element.
- **Fast Insertions/Deletions:** Insertions and deletions can be done anywhere in constant time without relocating other elements.
- **Sequential Access:** Does not provide random access. Accessing a particular element requires sequential traversal (linear time).
- **Non-Contiguous Memory:** Elements are allocated separately, leading to poor cache usage and slower traversal performance.
- **Usage:** Ideal when frequent modifications in the middle of the collection are needed without the requirement for rapid index-based access.

#### Example Usage of std::list
````cpp
#include <iostream>
#include <list>

int main() {
    std::list<int> lst;

    // Inserting elements. Insertion can happen at any position.
    lst.push_back(100);
    lst.push_back(200);
    lst.push_front(50);

    // Iterating through the list using an iterator
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}
````

## Comparative Summary

| Characteristic       | std::vector              | std::deque                  | std::list                        |
|----------------------|--------------------------|-----------------------------|----------------------------------|
| Memory Structure     | Contiguous               | Contiguous Segments         | Non-Contiguous Nodes             |
| Random Access        | Yes (Constant Time)      | Yes (Nearly Constant Time)  | No (Linear Time)                 |
| Insertion/Deletion   | Fast at the end          | Fast at both ends           | Fast anywhere                    |
| Cache Performance    | Excellent                | Good (but less than vector) | Poor                             |
| Typical Usage        | Dynamic Array            | Flexible Double-Ended Queue | Linked List for Frequent Changes |

## About Iterators

Iterators are a generalization of pointers and are used to traverse the elements of a container. They provide a uniform interface for iterating through elements, regardless of the underlying container type.

- **Random-Access Iterators:** Supported by `std::vector` and `std::deque`. They allow you to:
  - Access any element efficiently using an index offset.
  - Perform arithmetic operations (e.g. adding an integer to move forward/backward).
- **Bidirectional Iterators:** Provided by `std::list`. They allow:
  - Traversal in both forward and backward directions.
  - However, they do not support random access and require sequential traversal for accessing elements.

#### Example of Iterators with std::vector
````cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {10, 20, 30, 40};
    
    // Using an iterator to traverse the vector
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}
````
