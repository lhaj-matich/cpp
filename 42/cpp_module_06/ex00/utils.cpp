#include <iostream>

int count_occurence(std::string &s, char c)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while (s[i])
    {
        if (s[i] == c)
            count += 1;
        i++;
    }
    return (count);
}

bool check_nan(std::string &literal)
{
    if (!literal.compare("nan") || !literal.compare("nanf"))
        return (true);
    return (false);
}

bool check_numbers_extrem(std::string &literal)
{
    if (!literal.compare("+inff") || !literal.compare("inff") || !literal.compare("+inf") || !literal.compare("inf") || !literal.compare("-inf") || !literal.compare("-inff"))
        return (true);
    return (false);
}

bool error_number()
{
    std::cout << "Error: invalid number." << std::endl;
    return false;
}

void error_code()
{
    std::cout << "Error: invalid input." << std::endl;
}

bool check_int(std::string &number)
{
    if (count_occurence(number, '+') > 1 || count_occurence(number, '-') > 1)
        return (error_number());
    return (number.find_first_not_of("+-0123456789") == std::string::npos);
}

bool check_float(std::string &number)
{
    if (count_occurence(number, '+') > 1 || count_occurence(number, '-') > 1 || count_occurence(number, '.') > 1)
        return (error_number());
    return (number.find_first_not_of("+-0123456789.f") == std::string::npos);
}

bool check_double(std::string &number)
{
    if (count_occurence(number, '+') > 1 || count_occurence(number, '-') > 1 || count_occurence(number, '.') > 1)
        return (error_number());
    return (number.find_first_not_of("+-0123456789.") == std::string::npos);
}

void    display_nan_output()
{
    std::cout << "char: Impossible" << std::endl;
    std::cout << "int: Impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
}

void    display_inf_output()
{
    std::cout << "char: Impossible" << std::endl;
    std::cout << "int: Impossible" << std::endl;
    std::cout << "float: inff" << std::endl;
    std::cout << "double: inf" << std::endl;
}