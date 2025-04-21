
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
    bank.createAccount(5, 500);

    cout << bank << endl;
    bank.depositToAccount(1, 100);
    bank.depositToAccount(2, 200);
    bank.deleteAccount(3);
    cout << bank << endl;
    bank.giveLoan(4, 80);

    bank.withdrawFromAccount(1, 50);
    cout << bank << endl;
    
    return (0);
}
