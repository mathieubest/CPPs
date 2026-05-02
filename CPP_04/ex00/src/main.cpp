#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"

int main()
{
    const Animal* i = new Animal();
    const Animal* j = new Dog();
    const Animal* k = new Cat();

    std::cout << i->getType() << std::endl;
    std::cout << j->getType() << std::endl;
    std::cout << k->getType() << std::endl;

    std::cout << "Animal does: ";
    i->makeSound();
    std::cout << "Dog does: ";
    j->makeSound();
    std::cout << "Cat does: ";
    k->makeSound();

    delete i;
    i = j;
    i->makeSound();
    
    delete j;
    delete k;
    return (0);
}