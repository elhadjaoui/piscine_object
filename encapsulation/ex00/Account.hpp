#include <iostream>
#include <vector>

#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

class Bank;

class Account
{
private:
    int id;
    int value;

    Account(int id, int value = 0) : id(id), value(value) {}
    void deposit(int amount)
    {
        value += amount;
    }

    void withdraw(int amount)
    {
        if (amount <= value)
            value -= amount;
        else
            std::cerr << "Insufficient funds" << std::endl;
    }

public:

    const int &getId() const
    {
        return id;
    }

    const int &getValue() const
    {
        return value;
    }

    friend std::ostream &operator<<(std::ostream &p_os, const Account &p_account)
    {
        p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
        return p_os;
    }
    friend class Bank;
};

#endif
