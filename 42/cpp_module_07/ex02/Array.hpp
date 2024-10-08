#pragma once

#include <iostream>
#include <exception>

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
        T  & operator[](unsigned int index);
        const T & operator[](unsigned int index) const;
        unsigned int size ();
};

#include "Array.tpp"