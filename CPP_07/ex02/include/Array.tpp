#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <iostream>
#include <exception>

#define RED "\033[0;31m"
#define RESET "\033[0m"

template <typename T>
class Array {
    private:
        T *array;
        unsigned int _size;
    
    public:
        Array() : array(NULL), _size(0) {}

        Array(unsigned int n) : _size(n) {
            array = new T[n]();
        }

        Array(const Array &copy) : _size(copy._size) {
            array = new T[_size];
            for (unsigned int i = 0; i < _size; i++) {
                array[i] = copy.array[i];
            }
        }

        Array &operator=(const Array &other) {
            if (this != &other) {
                delete[] array;
                _size = other._size;
                array = new T[_size];
                for (unsigned int i = 0; i < _size; i++) {
                    array[i] = other.array[i];
                }
            }
            return *this;
        }

        ~Array() {
            delete[] array;
        }

        T &operator[](int index) {
            if (index < 0 || static_cast<unsigned int>(index) >= _size) {
                throw OutOfRangeException();
            }
            return array[index];
        }

        const T &operator[](int index) const {
            if (index < 0 || static_cast<unsigned int>(index) >= _size) {
                throw OutOfRangeException();
            }
            return array[index];
        }

        unsigned int size() const {
            return _size;
        }

        class OutOfRangeException : public std::exception {
            public:
                const char *what() const throw() {
                    return RED "Index is out of range" RESET;
                };
        };
};


// template <typename T>
// class Array {
//     private:
//         T *array;
//         unsigned int _size;
    
//     public:
//         class OutOfRangeException : public std::exception {
//             public:
//                 const char *what() const throw();
//         };
//         Array();

//         Array(unsigned int n);

//         Array(const Array &copy);

//         Array &operator=(const Array &other);

//         ~Array();

//         T &operator[](int index);

//         unsigned int size() const;

// };

#endif
