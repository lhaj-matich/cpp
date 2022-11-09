#include <iostream>
#include <sstream>

static int stoi( std::string & s ) {
    int i;
    std::istringstream(s) >> i;
    return i;
}

bool check_int(std::string &number)
{
    return (number.find_first_not_of("012345679"));
}

int main(int argc, char **argv)
{
    std::string literal; 
    if (argc > 2)
    {
        literal = argv[1];
        literal.find_first_not_of("0123456789");
    }
    return (0);
}