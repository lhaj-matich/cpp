#include "Span.hpp"

int main(void)
{
    // {
    //     try 
    //     {
    //         Span sp = Span(5);
    //         sp.addNumber(6);
    //         sp.addNumber(3);
    //         sp.addNumber(17);
    //         sp.addNumber(9);
    //         sp.addNumber(11);
    //         std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    //         std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    //     }
    //     catch (std::exception &e)
    //     {
    //         std::cout << e.what() << std::endl;
    //     }
    // }
    // {
    try 
    {
        Span sp = Span(5);
        int table[5] = {5,2,6,7,2};
        sp.addRange(table);
        // std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        // std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}