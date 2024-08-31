
#include "Account.hpp"
#include "Bank.hpp"

using namespace std;
int main()
{
    Bank bank;

    bank.createAccount(1, 100);
    bank.createAccount(2, 200);
    bank.createAccount(3, 300);
    bank.createAccount(4, 400);
    bank.createAccount(5, 500);
    cout << bank << endl;
    bank.depositToAccount(1, 100);
    bank.depositToAccount(2, 200);
    bank.deleteAccount(3);
    cout << bank << endl;
    bank.giveLoan(4, 80);
    cout << bank << endl;

    // cout << account.getId() << endl;
    
    return (0);
}
