#pragma once

#include <deque>
#include <stack>
#include <iostream>

template <class T, class Container = std::deque<T> >

class MutantStack : public std::stack<T, Container>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;

        MutantStack()
        {
            std::cout << "Default constructor has been called." << std::endl;
        }
        ~MutantStack()
        {
            std::cout << "Default destructor has been called." << std::endl;
        }
        MutantStack(MutantStack const & copy)
        {
            *this = copy;
        }
        MutantStack &operator=(MutantStack const & obj)
        {
            this->c = obj.c;
            return (*this);
        }

        iterator begin()
        {
            return (this->c.begin());
        }

        iterator end()
        {
            return (this->c.end());
        }
};