#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>
int main(void)
{
    {
        std::vector<int> a;
        a.push_back(4);
        a.push_back(6);
        a.push_back(1);
        a.push_back(9);
        a.push_back(14);
        int index = easyfind<std::vector<int> > (a, 9);
        std::cout << "Value: " << index << std::endl;
    }
    {
        std::list<int> l;
        l.push_back(5);
        l.push_back(7);
        l.push_back(2);
        l.push_back(1);
        l.push_back(6);
        l.push_back(8);
        int index = easyfind<std::list<int> >(l, 17);
        std::cout << "Value: " << index << std::endl;
    }
}