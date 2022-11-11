#ifndef _CONVERTNUMBER_HPP
#define _CONVERTNUMBER_HPP

#include <iostream>
#include <sstream>
#include <limits.h>
#include <float.h>
#include <stdint.h>
#include <iomanip>

#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4

bool check_int(std::string &number);
bool check_float(std::string &number);
bool check_double(std::string &number);
long int string_to_i( std::string & s );
double string_to_d(std::string & s);
float string_to_f(std::string & s);
void error_code();
bool error_number();
bool check_numbers_extrem(std::string &literal);
bool check_nan(std::string &literal);
void    display_nan_output();
void    display_inf_output();

#endif