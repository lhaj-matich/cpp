#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    try {
        BitcoinExchange instance;
        instance.calculateRates("input.txt");
    } catch (ExchangeError &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}