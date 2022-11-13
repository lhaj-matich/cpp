#include "convertNumber.hpp"

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

bool check_valid(std::string & literal)
{
    if (check_numbers_extrem(literal) || check_nan(literal))
        return (true);
    else if (literal.length() == 1 && isprint(literal[0]))
        return (true);
    else if (check_float(literal))
        return (true);
    return (false);
}

int main(int argc, char **argv)
{
    std::string literal; 
    if (argc > 1)
    {
        literal = argv[1];
        if (!check_valid(literal))
            return (error_code(), 0);
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