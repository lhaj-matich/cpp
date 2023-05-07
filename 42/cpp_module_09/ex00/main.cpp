#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    try {
        BitcoinExchange instance;
        if (argc < 2)
            throw ExchangeError("Error: could not open file.");
        instance.calculateRates(argv[1]);
    } catch (ExchangeError &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
