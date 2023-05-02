#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
        return (0);
    try 
    {
        PmergeMe set;
        set.SortNumbers(argv, argc);
    }
    catch (PmergeMeError &e)
    {
        std::cout << e.what() << std::endl;       
    }
    return (0);
}