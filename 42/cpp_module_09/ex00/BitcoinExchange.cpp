#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() { this->loadDatabase(); }

BitcoinExchange::~BitcoinExchange(){}

void    BitcoinExchange::loadDatabase()
{
    std::ifstream   file("data.csv");
    std::string     *result;
    std::string     date;
    std::string     line;
    float           exchange_rate;

    if (file.is_open()) {
        if (file.peek() == EOF)
            throw ExchangeError("Error: empty data.csv file.");
        while (std::getline(file, line)) 
        {
            result = split(line, ',');
            if (this->check_table(result) && this->check_date(result[0]))
            {
                exchange_rate = std::atof(result[1].c_str());
                date = result[0];
                this->_exchangeDatabase.insert(std::make_pair(date, exchange_rate));
            }
            delete [] result;
        }
        file.close();
    }
    else 
        throw ExchangeError("Error: could not open data.csv, please provide a valid one.");
}

void    BitcoinExchange::calculateRates(std::string filename)
{
    std::ifstream   file(filename.c_str());
    std::string     line;
    std::string     date;
    std::string     *result;
    std::string     raw_amount;
    float           btc_amount;

    if (this->_exchangeDatabase.size() == 0)
        return ;
    if (file.is_open()) {
        while (std::getline(file, line)) 
        {
            if (line.find(" | ") != std::string::npos)
            {
                result = split(line, '|');
                if (this->check_table(result) && this->check_date(result[0]) && this->check_number(result[1]))
                {
                    raw_amount = stripSpaces(result[1]);
                    if (raw_amount.find(".") == 0 || raw_amount.find(".") == (raw_amount.length() - 1))
                        std::cout << "Error: invalid => " << line << std::endl;
                    else 
                    {
                        btc_amount = std::atof(raw_amount.c_str());
                        date = stripSpaces(result[0]);
                        std::cout << date << " => " << btc_amount << " = " << btc_amount * this->getExchangeRate(date) << std::endl;
                    }
                }
                delete [] result;
            }
            else
                std::cout << "Error: bad input => " << line << std::endl;
        }
        file.close();
    }
    else 
        throw ExchangeError("Error: could not open the input file, please provide a valid one.");
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
    if (table == NULL || table[0].empty() || table[1].empty())
        return (false);
    return (true);
}

std::string *split(std::string line, char del)
{
    std::string *result;
    size_t      pos;

    result = new std::string[2];
    pos = line.find(del);
    if (pos != std::string::npos)
    {
        result[0] = line.substr(0, pos);
        result[1] = line.substr(pos + 1, line.length() - pos - 1);
        return (result);
    }
    return (NULL);
}

double   BitcoinExchange::getExchangeRate(std::string & date)
{
    std::map<std::string, double>::iterator it;

    it = this->_exchangeDatabase.find(date);
    if (it == this->_exchangeDatabase.end())
        return (std::prev(this->_exchangeDatabase.lower_bound(date))->second);
    return (it->second);
}

bool    BitcoinExchange::check_leap(int year)
{
    if ((year % 4 == 0) || ((year % 100 == 0) && (year % 400 == 0)))
        return true;
    return false;
}

bool    BitcoinExchange::check_date(std::string &date)
{
    std::tm dateStruct = {};
    std::istringstream ss(date.c_str());

    if (date.find("date") != std::string::npos)
        return (false);
    if (strptime(date.c_str(), "%Y-%m-%d", &dateStruct) == NULL)
        return (std::cout << "Error: bad input => " << date << std::endl, false);
    if ((dateStruct.tm_mon + 1) == 2 && dateStruct.tm_mday > 28 && !check_leap(dateStruct.tm_year + 1900))
        return (std::cout << "Error: bad input => " << date << std::endl, false);
    if ((dateStruct.tm_mon + 1) == 2 && dateStruct.tm_mday > 29 && check_leap(dateStruct.tm_year + 1900))
        return (std::cout << "Error: bad input => " << date << std::endl, false);
    if ((dateStruct.tm_mon + 1) == 8 && dateStruct.tm_mday == 31)
        return (true);
    if ((dateStruct.tm_mon + 1) % 2 == 0 && dateStruct.tm_mday > 30 && dateStruct.tm_mon < 8)
        return (std::cout << "Error: bad input => " << date << std::endl, false);
    if ((dateStruct.tm_mon + 1) % 2 != 0 && dateStruct.tm_mday > 30 && dateStruct.tm_mon > 8)
        return (std::cout << "Error: bad input => " << date << std::endl, false);
    return (true);
}

bool    BitcoinExchange::check_numeric(std::string str)
{
    size_t index;

    index = 0;
    while (index < str.length())
    {
        if (!isdigit(str[index]) && !isspace(str[index]) && str[index] != '.' && str[index] != '-')
            return (false);
        index += 1;
    }
    return (true);
}

bool    BitcoinExchange::check_number(std::string &input)
{
    float   value;

    if (input.find("value") != std::string::npos)
        return (false);
    else if (!this->check_numeric(input))
        return (std::cout << "Error: invalid number format: " << input << std::endl ,false);
    try 
    {
        value = std::atof(input.c_str());
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