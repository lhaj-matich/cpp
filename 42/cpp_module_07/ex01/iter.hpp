#ifndef _ITER_HPP_
# define _ITER_HPP_

# include <iostream>

template <typename T>
void print(T const & var)
{
    std::cout << var << std::endl;
}

template <typename T>
void iter(T *table, int length, void (*fun)(T const &)) {
    int i;

    i = 0;
    while (i < length)
    {
        fun(table[i]);
        i++;
    }
}

#endif