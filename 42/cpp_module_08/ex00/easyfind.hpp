#pragma once

#include <algorithm>

template <typename T>
int easyfind(T value, int index)
{
    typedef typename T::iterator Iter; // the typename keyword lets the compiler know that the type that we're using is not static.
    Iter begin = value.begin();
    Iter end = value.end();
    Iter pos;
    
    pos = std::find(begin, end, index);
    if  (pos != end)
        return (*pos);4
    return (-1);
}