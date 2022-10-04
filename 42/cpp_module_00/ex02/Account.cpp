#include "./Account.hpp"
#include <iostream>
#include <ctime>

int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_nbAccounts = 0;

int	Account::getNbAccounts( void )
{
    return Account::_nbAccounts;
}

int Account::getTotalAmount( void )
{
    return Account::_totalAmount;
}

int Account::getNbDeposits( void )
{
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals( void )
{
    return Account::_totalNbWithdrawals;
}

int Account::checkAmount( void ) const
{
    return this->_amount;
}

void    Account::makeDeposit(int deposite) 
{
    int amount;

    amount = _amount;
    if (deposite > 0 && deposite < INT_MAX)
    {
        _amount += deposite;
        _nbDeposits += 1;
        _totalAmount += deposite;
        _totalNbDeposits += 1;
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";p_amount:" << amount << ";deposit:" << deposite << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
    }
}

bool    Account::makeWithdrawal(int widthrawal)
{
    int amount;

    amount = this->checkAmount();
    _displayTimestamp();
    if (widthrawal > 0)
    {
        if (amount > widthrawal)
        {
            _amount -= widthrawal;
            _nbWithdrawals += 1;
            _totalAmount -= widthrawal;
            _totalNbWithdrawals += 1;
            std::cout << "index:" << _accountIndex << ";p_amount:" << amount << ";withdrawal:" << widthrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
            return (true);
        }
    }
    std::cout << "index:" << _accountIndex << ";p_amount:" << amount << ";withdrawal:refused" << std::endl;
    return (false);
}

void    Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}


void    Account::displayStatus( void ) const 
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void    Account::_displayTimestamp( void )
{
    char buffer[256];

    time_t now = time(0);
    tm *ltm = localtime(&now);
    strftime(buffer, sizeof(buffer), "%d%m%G_%H%M%S", ltm);

    std::cout << "[" << buffer << "] ";
}

Account::Account()
{
    std::cout << "The default constructor is called" << std::endl;
}


Account::Account(int initialDeposit)
{
    _displayTimestamp();
    
    _accountIndex = getNbAccounts();
    _amount = initialDeposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _totalAmount += initialDeposit;
    _nbAccounts += 1;
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}