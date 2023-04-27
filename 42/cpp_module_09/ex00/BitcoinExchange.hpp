#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>

class	BitcoinExchange
{
    private:
        std::map<std::string, float> _exchangeDatabase;

        bool    check_date(std::string & date);
        bool    check_number(std::string & value);
        bool    check_table(std::string *table);
        void    loadDatabase();
        float   getExchangeRate(std::string & date);
    public:
        void    calculateRates(std::string filename);
        BitcoinExchange(void);
        BitcoinExchange(BitcoinExchange const &src);

        ~BitcoinExchange(void);
};

std::string *split(std::string line, char del);
std::string stripSpaces(std::string &str);

#endif