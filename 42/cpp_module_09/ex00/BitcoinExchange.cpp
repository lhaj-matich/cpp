#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    this->loadDatabase();
    std::cout << "Default consturctor" << std::endl;
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
                this->_exchangeDatabase.insert(std::make_pair(date, exchange_rate));
            }
            delete [] result;
        }
        file.close();
    }
    else 
        std::cout << "Failed to open the database file!" << std::endl;
}

void    BitcoinExchange::calculateRates(std::string filename)
{
    std::ifstream   file(filename);
    std::string     line;
    std::string     date;
    std::string     *result;
    float           btc_amount;

    if (file.is_open()) {
        while (std::getline(file, line)) 
        {
            if (line.find(" | ") != std::string::npos)
            {
                result = split(line, '|');
                if (this->check_table(result) && this->check_date(result[0]) && this->check_number(result[1]))
                {
                    btc_amount = std::stof(stripSpaces(result[1]));
                    date = stripSpaces(result[0]);
                    std::cout << date << " => " << btc_amount << " = " << btc_amount * this->getExchangeRate(date) << std::endl;
                }
                delete [] result;
            }
            else
                std::cout << "Error: bad input => " << line << std::endl;
        }
        file.close();
    }
    else 
        std::cout << "Failed to open the input file!" << std::endl;
}

std::string stripSpaces(std::string &str){
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start == std::string::npos)
        return std::string();
    size_t end = str.find_last_not_of(" \t\n\r");
    return str.substr(start, end - start + 1);
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

float   BitcoinExchange::getExchangeRate(std::string & date)
{
    std::map<std::string, float>::iterator it;

    it = this->_exchangeDatabase.find(date);
    if (it == this->_exchangeDatabase.end())
    {
        it = this->_exchangeDatabase.lower_bound(date);
        this->getExchangeRate((std::string &)it->first);
    }
    else
        return (it->second);
}

bool    BitcoinExchange::check_date(std::string &date)
{
    std::tm dateStruct = {};
    std::istringstream ss(date.c_str());

    if (date.find("date") != std::string::npos)
        return (false);
    ss >> std::get_time(&dateStruct, "%Y-%m-%d");
    if (ss.fail())
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return (false);
    }
    return (true);
}

bool    BitcoinExchange::check_number(std::string &input)
{
    float   value;

    if (input.find("value") != std::string::npos)
        return (false);
    try {
        value = std::stof(input);
        if (value < 0)
            return (std::cout << "Error: not a positive number." << std::endl ,false);
        else if (value > 1000)
            return (std::cout << "Error: too large a number." << std::endl ,false);
    } 
    catch (std::exception& e)
    {
        return (std::cout << "Error: " << std::endl ,false);
    }
    return (true);
}