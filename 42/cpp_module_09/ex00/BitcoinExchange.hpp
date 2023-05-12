#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <exception>

class	BitcoinExchange
{
    private:
        std::map<std::string, double> _exchangeDatabase;

        bool    check_date(std::string & date);
        bool    check_number(std::string & value);
        bool    check_numeric(std::string & value);
        bool    check_table(std::string *table);
        void    loadDatabase();
        double   getExchangeRate(std::string & date);
    public:
        void    calculateRates(std::string filename);
        BitcoinExchange(void);
        BitcoinExchange(BitcoinExchange const &src);

        ~BitcoinExchange(void);
};

class ExchangeError: public std::runtime_error
{
    public:
        ExchangeError (std::string const& msg):
            std::runtime_error(msg)
        {}
};

std::string *split(std::string line, char del);
std::string stripSpaces(std::string &str);

#endif