#include "Span.hpp"

int difference(int x, int y)
{
    return (abs(x - y));
}

Span::Span()
{
    this->_size = 0;
    std::cout << "The default constructor has been called." << std::endl;
}

Span::Span(unsigned int size)
{
    std::cout << "Params constructor has been called." << std::endl;
    this->_size = size;
}

Span::~Span()
{
    std::cout << "Destructor has been called." << std::endl;
}

Span & Span::operator=(const Span & assign)
{
    std::cout << "Copy assign operator overload called." << std::endl;
    this->_table = assign._table;
    this->_size = assign._size;
    return (*this);
}

Span::Span(const Span & copy)
{
    std::cout << "Copy constructor called." << std::endl;
    *this = copy;
}

unsigned int    Span::spanSize()
{
    return (this->_table.size());
}

void    Span::addNumber(unsigned int value)
{
    if (this->_table.size() == _size)
        throw SpanAlreadyFull();
    else
        this->_table.push_back(value);
}

int     Span::longestSpan()
{
    typedef std::vector<int>::iterator iter;
    if (this->spanSize() == 0)
        throw SpanEmpty();
    iter begin = this->_table.begin();
    iter end = this->_table.end();
    int adj_table[this->_size];
    std::adjacent_difference(begin, end, adj_table, difference);
    return (*std::max_element(adj_table, adj_table + this->spanSize()));
    return (0);
}

int     Span::shortestSpan()
{
    typedef std::vector<int>::iterator iter;
    if (this->spanSize() == 0)
        throw SpanEmpty();
    int adj_table[this->_size];
    iter begin = this->_table.begin();
    iter end = this->_table.end();
    std::adjacent_difference(begin, end, adj_table, difference);
    return (*std::min_element(adj_table, adj_table + this->spanSize()));
}

const char *Span::SpanAlreadyFull::what() const throw()
{
    return ("Exception::SpanAlreadyFull");
}

const char *Span::SpanEmpty::what() const throw()
{
    return ("Exception::SpanEmpty");
}