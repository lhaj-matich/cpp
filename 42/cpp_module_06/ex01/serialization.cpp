#include "serialization.hpp"

uintptr_t serialize(Data* ptr)
{
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    return (raw);
}

Data* deserialize(uintptr_t raw)
{
    Data *data = reinterpret_cast<Data *>(raw);
    return (data);
}