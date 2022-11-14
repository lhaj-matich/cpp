#pragma once

template <class T>
Array<T>::Array()
{
    std::cout << "Default constructor called" << std::endl;
    this->_size = 0;
    this->table = NULL;
}

template <class T>
Array<T>::Array(unsigned int table_size)
{
    std::cout << "Paramtrized constructor called" << std::endl;
    this->_size = table_size;
    this->table = new T[table_size];
}

template <class T>
Array<T>::Array(const Array & copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->table = NULL;
    *this = copy;
}

template <class T>
Array<T>::~Array()
{
    std::cout << "Destructor called" << std::endl;
    if (this->table)
        delete [] this->table;
}

template <class T>
Array<T> & Array<T>::operator=(const Array<T> &copy)
{
    std::cout << "Copy assign operator overload." << std::endl;
    if (this->table)
        delete [] this->table;
    this->table = new T[copy._size];
    this->_size = copy._size;
    for (unsigned int i = 0; i < this->_size; i++)
        this->table[i] = copy.table[i];
    return (*this);
}

template <class T>
T & Array<T>::operator[](unsigned int index)
{
    if (index > this->_size)
        throw Array<T>::ArrayOutOfBounds();
    return (this->table[index]);
}

template <class T>
const T & Array<T>::operator[](unsigned int index) const
{
    if (index > this->_size)
        throw Array<T>::ArrayOutOfBounds();
    return (this->table[index]);
}

template <class T>
const char * Array<T>::ArrayOutOfBounds::what() const throw() 
{
    return ("ArrayOutOfBoundsException");
}

template <class T>
unsigned int Array<T>::size()
{
    return (this->_size);
}