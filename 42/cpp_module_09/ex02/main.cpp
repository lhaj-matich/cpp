#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    try 
    {
        PmergeMe set;
        if (argc < 2)
            throw PmergeMeError("Error: please provide a valid set of numbers.");
        set.SortNumbers(argv, argc);
    }
    catch (PmergeMeError &e)
    {
        std::cout << e.what() << std::endl;       
    }
    return (0);
}