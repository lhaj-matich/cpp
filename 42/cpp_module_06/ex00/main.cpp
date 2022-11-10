#include <iostream>
#include <sstream>
#include <limits.h>
#include <float.h>
#include <stdint.h>
#include <iomanip>
#include "convertNumber.hpp"

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

void    display_nan_output()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
}

void    display_inf_output()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: inff" << std::endl;
    std::cout << "double: inf" << std::endl;
}

long int string_to_i( std::string & s ) {
    long int i;
    std::istringstream(s) >> i;
    return i;
}

double string_to_d(std::string & s)
{
    double d;
    std::istringstream(s) >> d;
    return d;
}

float string_to_f(std::string & s) 
{
    float f;
    std::istringstream(s) >> f;
    return f;
}

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

int get_literal_type(std::string &s)
{
    if (s.length() == 1 && isalpha(s[0]))
        return (CHAR);
    else if (check_int(s))
        return (INT);
    else if (check_double(s))
        return (DOUBLE);
    else if (check_float(s))
        return (FLOAT);
    return (0);
}

int get_precesion(std::string &s)
{
    int cut = s.find('.', 0);
    return (s.length() - (cut + 1));
}  

void    print_result(int type, std::string &s)
{
    double      d = 0.0; 
    float       f = 0.0;
    char        c = 0;
    long int    i = 0;
    long int    check = 0;
    int         precision = get_precesion(s);
    if (type == CHAR)
    {
        c = s[0];
        if (isprint(c))
        {
            d = static_cast<double>(c);
            i = static_cast<int>(c);
            f = static_cast<float>(c);
        }
    }
    else if (type == INT)
    {
        i = string_to_i(s);
        if (i > INT_MAX || i < INT_MIN)
            return (error_code());
        f = static_cast<float>(i);
        d = static_cast<double>(i);
        c = static_cast<char>(i);
    }
    else if (type == DOUBLE)
    {
        d = string_to_d(s);
        check = string_to_i(s);
        i = static_cast<int>(d);
        f = static_cast<float>(d);
        c = static_cast<char>(d);
    }
    else if (type == FLOAT)
    {
        s.pop_back();
        f = string_to_f(s);
        check = string_to_i(s);
        i = static_cast<int>(f);
        d = static_cast<float>(f);
        c = static_cast<char>(f);
    }
    if (check > INT_MAX || check < INT_MIN)
        std::cout << "Int: Impossible" << std::endl;
    else
        std::cout << "Int: " << i << std::endl;
    std::cout << "Double: " <<  std::fixed  << std::setprecision(precision) << d << std::endl;
    std::cout << "Float: " << std::fixed  << std::setprecision(precision) << f << "f" << std::endl; 
    if (i > 255 || i < 0)
        std::cout << "Char: Impossible" << std::endl;
    else if (!isprint(c))
        std::cout << "Char: Non displayable" << std::endl;
    else
        std::cout << "Char: " << c << std::endl; 
}

int main(int argc, char **argv)
{
    std::string literal; 
    if (argc > 1)
    {
        literal = argv[1];
        if (check_numbers_extrem(literal))
            display_inf_output();
        else if (check_nan(literal))
            display_nan_output();
        else
            print_result(get_literal_type(literal), literal);
        return (0);
    }
    std::cout << "Invalid input" << std::endl;
}