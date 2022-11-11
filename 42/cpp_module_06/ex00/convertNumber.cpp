#include <iostream>
#include <sstream>

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