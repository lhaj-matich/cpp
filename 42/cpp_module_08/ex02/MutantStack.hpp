#pragma once

#include <deque>
#include <stack>
#include <iostream>

template <class T, class Container = std::deque<T>>

class MutantStack : public std::
{
    public:
        MutantStack();
        ~MutantStack();
        MutantStack(const & MutantStack);
        MutantStack &operator=(const & MutantStack);

        
        // Member functions
};