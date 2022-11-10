#include <iostream>
#include <sstream>
#include <limits.h>
#include <float.h>


int stoi( std::string & s ) {
    int i;
    std::istringstream(s) >> i;
    return i;
}

char stoc(std::string & s) 
{
    char c;
    std::istringstream(s) >> c;
    return c;
}

double stod(std::string & s)
{
    double d;
    std::istringstream(s) >> d;
    return d;
}

float stof(std::string & s) 
{
    float f;
    std::istringstream(s) >> f;
    return f;
}