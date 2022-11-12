#include "iter.hpp"

int main(void)
{
    {
        std::string table[5] = {"Hello", "World", "We", "Just", "Starting"};
        ::iter(table, 5, ::print);
    }
    {
        int table[5] = {5, 3, 4, 1, 8};
        ::iter(table, 5, ::print);
    }
    {
        float table[5] = {5.2, 1.82, 16.2, 26, 15};
        ::iter(table, 5, ::print);
    }
}