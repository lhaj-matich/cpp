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
        std::map<std::string, float> _map;
        bool    check_date(std::string & date);
        bool    check_number(std::string & value);
        void    loadDatabase();
    public:
        BitcoinExchange(void);
        BitcoinExchange(std::string filename);
        BitcoinExchange(BitcoinExchange const &src);

        ~BitcoinExchange(void);
};
#endif