#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <exception>
#include <algorithm>
#include <numeric>
#include <cmath>

class Span 
{
    public:
        Span();
        Span(unsigned int);
        ~Span();
        Span(Span const & copy);
        Span & operator=(Span const & assign);

        class SpanAlreadyFull : public std::exception
        {
            const char *what() const throw();
        };

        class SpanEmpty : public std::exception
        {
            const char *what() const throw();
        };

        int     shortestSpan( void );
        int     longestSpan( void );
        // Member functions
        void addNumber(unsigned int);
        
        template <typename T>
        void    addNumber(T begin, T end)
        {
            T iter = begin;
            unsigned int size = std::distance(begin, end);
            if (size <= this->spanSize())
                throw SpanAlreadyFull();
            while (iter != end)
            {
                this->_table.push_back(*iter);
                iter++;
            }
        }
    private:
        unsigned int _size;
        unsigned int spanSize( void );
        std::vector<int> _table;

};