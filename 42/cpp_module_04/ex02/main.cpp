#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    Animal *group[8];
    Cat cat;
    Cat cat2(cat);
    Dog dog;
    Dog dog2(dog);

    for (int i = 0; i <= 8; i++)
    {
        if (i % 2)
            group[i] = new Cat();
        else
            group[i] = new Dog();
    }
    for (int i = 0; i <= 8; i++)
        delete group[i];
}