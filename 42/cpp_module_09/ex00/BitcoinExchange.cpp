#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::cout << "Default consturctor" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string input)
{
    std::ifstream   file(input);
    std::string     line;
    std::string     date;
    std::string     *result;
    float           btc_amount;

    // Load the exchange rate database.
    this->loadDatabase();
    if (file.is_open()) {
        while (std::getline(file, line)) 
        {
            result = split(line, '|');
            if (this->check_table(result) && this->check_date(result[0]), this->check_number(result[1]))
            {
                btc_amount = std::stof(result[1]);
                date = result[0];
            }
            delete [] result;
        }
        file.close();
    }
    else 
        std::cout << "Failed to open the database file!" << std::endl;
}


BitcoinExchange::~BitcoinExchange()
{
    std::cout << "Default destructor" << std::endl;
}

void    BitcoinExchange::loadDatabase()
{
    std::ifstream   file("data.csv");
    std::string     *result;
    std::string     date;
    std::string     line;
    float           exchange_rate;

    if (file.is_open()) {
        while (std::getline(file, line)) 
        {
            result = split(line, ',');
            if (this->check_table(result) && this->check_date(result[0]))
            {
                exchange_rate = std::stof(result[1]);
                date = result[0];
                this->_exchange_database.insert(std::make_pair(date, exchange_rate));
            }
            delete [] result;
        }
        file.close();
    }
    else 
        std::cout << "Failed to open the database file!" << std::endl;
}

bool    BitcoinExchange::check_table(std::string *table)
{
    if (!table || table[0].empty() || table[1].empty())
        return (false);
    return (true);
}

std::string *split(std::string line, char del)
{
    std::string *result;
    size_t      pos;
    size_t      index;

    result = new std::string[2];
    index = 0;
    pos = line.find(del);
    if (pos != std::string::npos)
    {
        result[0] = line.substr(0, pos);
        result[1] = line.substr(pos + 1, line.length() - pos - 1);
        return (result);
    }
    return (NULL);
}

bool    BitcoinExchange::check_date(std::string &date)
{
    std::tm dateStruct = {};
    std::istringstream ss(date.c_str());

    ss >> std::get_time(&dateStruct, "%Y-%m-%d");
    if (ss.fail())
        return (false);
    return (true);
}

bool    BitcoinExchange::check_number(std::string &input)
{
    float   value;

    value = std::stof(input);
    if (value < 0 || value > 1000)
        return (false);
    return (true);
}