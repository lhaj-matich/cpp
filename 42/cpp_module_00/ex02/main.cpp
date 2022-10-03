#include "./Account.hpp"

int main(void)
{
    Account account(50);
    Account account2(300);

    account.displayAccountsInfos();
    account.displayStatus();
    account.makeDeposit(7300);
    account.displayStatus();
}