#pragma once

#include <iostream>

template <class T>
class Array {
    private:
        T *table;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int size);
        Array(const Array & copy);
        ~Array();
        class ArrayOutOfBounds : public std::exception 
        {
            public:
                const char * what() const throw();
        };
        Array& operator=(const Array & table);
        T   operator[](unsigned int index);
        unsigned int size ();
};

#include "Array.tpp"