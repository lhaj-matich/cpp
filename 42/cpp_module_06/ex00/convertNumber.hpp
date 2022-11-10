#ifndef _CONVERTNUMBER_HPP
#define _CONVERTNUMBER_HPP

#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4

int stoi( std::string & s );
double stod( std::string & s );
float stof( std::string & s );
char stoc( std::string & s );
int float_exponent(float f);
int float_mantissa(float f);

#endif