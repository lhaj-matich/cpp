#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    std::cout << "Dynamic binding." << std::endl;
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();

        delete i;
        delete j;
        delete meta;
    }
    std::cout << "Static binding." << std::endl;
    {
        WrongAnimal* meta = new WrongAnimal();
        WrongAnimal* j = new WrongCat();
        meta->makeSound();
        j->makeSound();
    }
    return 0;
}