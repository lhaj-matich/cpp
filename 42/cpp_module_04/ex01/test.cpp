#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    delete j;
    delete i;
    // while (1);
    return (0);
}