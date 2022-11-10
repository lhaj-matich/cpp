#include <iostream>
#include <sstream>
#include <limits.h>
#include <float.h>
#include "convertNumber.hpp"

void    handle_char(std::string &literal)
{
    int ascii = stoi(literal);

    if (check_nan(literal) || check_numbers_extrem(literal))
        std::cout << "impossible" << std::endl;
    if (ascii > 0 && ascii < 255)
        std::cout << "impossible" << std::endl;
    else if (ascii < 32 && ascii > 126)
        std::cout << "not displayable" << std::endl;  
    else
    {
        char c = static_cast<char>(ascii);
        std::cout << c << std::endl;
    }
}



void    print_result()
{
    std::cout << "char: " << std::endl;
    std::cout << "int: " << std::endl;
    std::cout << "float: " << std::endl;
    std::cout << "double: " << std::endl;
}

bool check_int(std::string &number)
{
    return (number.find_first_not_of("+-012345679"));
}

bool check_float(std::string &number)
{
    return (number.find_first_not_of("+-012345679.f"));
}

bool check_double(std::string &number)
{
    return (number.find_first_not_of("+-012345679."));
}

int get_literal_type(std::string &s)
{
    if (s.length() == 1 && isalpha(s[0]))
        return (CHAR);
    else if (check_int(s))
        return (INT);
    else if (check_float(s))
        return (FLOAT);
    else if (check_double(s))
        return (DOUBLE);
    return (0);
}

bool check_nan(std::string &literal)
{
    if (literal.compare("nan") || literal.compare("nanf"))
        return (true);
    return (false);
}

bool check_numbers_extrem(std::string &literal)
{
    if (literal.compare("+inff") || literal.compare("inff") || literal.compare("+inf") || literal.compare("inf") || literal.compare("-inf") || literal.compare("-inff"))
        return (true);
    return (false);
}

int main(int argc, char **argv)
{
    std::string literal; 
    if (argc > 1)
    {
        literal = argv[1];
        
        return (0);
    }
    std::cout << "Invalid input" << std::endl;
}