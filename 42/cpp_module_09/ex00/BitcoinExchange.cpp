#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::cout << "Default consturctor" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string input)
{
    std::cout << "Default consturctor" << std::endl;
}


BitcoinExchange::~BitcoinExchange()
{
    std::cout << "Default destructor" << std::endl;
}

void    BitcoinExchange::loadDatabase()
{
    std::ifstream file("data.csv");

    if (file.is_open()) {
        std::string line;

        while (std::getline(file, line)) 
        {
            std::cout << line << std::endl;
        }
        file.close();
    }
    else 
        std::cout << "Failed to open file!" << std::endl;
}

std::string *split(std::string line, char del)
{
    std::string *result = new std::string[2];
    size_t pos;
    size_t index;

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