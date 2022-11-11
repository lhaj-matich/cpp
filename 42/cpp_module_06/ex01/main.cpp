#include "serialization.hpp"

int main(void)
{
    Data be;

    be.age = 31;
    be.name = strdup("Oussama");
    uintptr_t raw = serialize(&be);
    Data *good = deserialize(raw);
    std::cout << "Name: " << good->name << std::endl;
    std::cout << "Age: " << good->age << std::endl;
    return (0);
}