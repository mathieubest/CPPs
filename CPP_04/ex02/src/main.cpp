#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"

#define NUM 10

int main()
{
    int num_of_animals = 10;
    AAnimal **animals = new AAnimal*[num_of_animals];
    
    for (int i = 0; i < num_of_animals; i++) {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    for (int i = 0; i < num_of_animals; i++) {
        animals[i]->makeSound();
        delete animals[i];
    }
    delete[] animals;
    return 0;
}