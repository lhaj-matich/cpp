#ifndef SERIALIZATION_HPP_
#define SERIALIZATION_HPP_

#include <iostream>

typedef struct Data 
{
    std::string name;
    int age;
} Data;

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif