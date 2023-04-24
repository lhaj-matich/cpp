#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>

class	BitcoinExchange
{
    private:
        std::map<std::string, float> _map;
        bool    check_date(std::string & date);
        bool    check_number(std::string & value);
    public:
        BitcoinExchange(void);
        BitcoinExchange(std::string filename);
        BitcoinExchange(BitcoinExchange const &src);
        BitcoinExchange& operator=(BitcoinExchange const &rhs);

        void	init_csv(void);
        int 	data_base(char const *av);
        ~BitcoinExchange(void);
};
#endif