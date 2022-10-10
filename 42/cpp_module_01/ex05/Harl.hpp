#ifndef _HARL_H_
#define _HARL_H_

#include <iostream>


enum Levels {debug, info, warning, error, invalid};

class Harl 
{
    private:
        void    debug( void );
        void    info( void );
        void    warning( void );
        void    error( void );
    public:
        void    complain(std::string level);  
};

typedef void    (Harl::*complains)(void);

void    appError( void );
Levels  findLevel(std::string level);

#endif
