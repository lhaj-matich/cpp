#include "MutantStack.hpp"

int main(void)
{
    MutantStack<int> mystack;
    mystack.push(4);
    mystack.push(18);
    mystack.push(33);
    MutantStack<int>::iterator begin = mystack.begin();
    MutantStack<int>::iterator end = mystack.end();
    while (begin != end)
    {
        std::cout << "The value:" << *begin << std::endl; 
        begin++;
    }
    return (0);
}