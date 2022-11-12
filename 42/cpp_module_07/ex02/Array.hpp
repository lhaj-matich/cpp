#include <exception>

template <class T>

class Array {
    private:
        T *table;
        unsigned int _size;
    public:
        Array()
        {
            this->_size = 0;
            this->table = NULL;
        }
        Array(unsigned int size)
        {
            this->_size = size;
            this->table = new T[size];
        }
        Array(const Array & copy)
        {
           *this = copy;
        }
        Array& operator=(const Array & table)
        {
            delete this->table;
            this->table = new T[size];
            for (int i = 0; i < this->_size; i++)
                this->table[i] = copy.table[i];
            return (*this);
        }
        T &operator[](int index) {
            if (index > size || size < 0)
                throw std::exception("InvalidArrayIndex");
            return (this->table[index]);
        }
        unsigned int size () 
        {
            return (this->_size);
        }
};