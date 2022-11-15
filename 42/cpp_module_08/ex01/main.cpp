#include "Span.hpp"

int main(void)
{
    std::cout << "=======Testing individual addNumber method.========" << std::endl;
    {
        try 
        {
            Span sp = Span(5);
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);
            std::cout << "Longest span: " << sp.longestSpan() << std::endl;
            std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "=======Testing range addNumber method.=========" << std::endl;
    {
        try 
        {
            srand(time(NULL));
            Span sp = Span(5);
            std::vector<int> victoria;
            for (int i = 0; i < 5; i++)
                victoria.push_back(rand() % 9);
            std::vector<int>::iterator begin = victoria.begin();
            std::vector<int>::iterator end = victoria.end();
            sp.addNumber(begin, end);
            std::cout << "Longest span: " << sp.longestSpan() << std::endl;
            std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "=======Testing range addNumber method with list.========" << std::endl;
    {
        try 
        {
            srand(time(NULL));
            Span sp = Span(5);
            std::list<int> listing;
            for (int i = 0; i < 5; i++)
                listing.push_back(rand() % 9);
            std::list<int>::iterator begin = listing.begin();
            std::list<int>::iterator end = listing.end();
            sp.addNumber(begin, end);
            std::cout << "Longest span: " << sp.longestSpan() << std::endl;
            std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    return (0);
}