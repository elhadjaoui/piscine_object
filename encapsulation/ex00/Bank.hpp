#include <iostream>
#include <vector>
#include "Account.hpp"

#ifndef BANK_HPP
#define BANK_HPP

class Bank {
private:
    int liquidity;
    std::vector<Account *> clientAccounts;

    bool isUniqueId(int id) const {
        for (std::vector<Account *>::const_iterator it = clientAccounts.begin(); it != clientAccounts.end(); ++it) {
            if ((*it)->getId() == id) {
                return false;
            }
        }
        return true;
    }

public:
    Bank() : liquidity(0) {}

    int getLiquidity() const {
        return liquidity;
    }

    void createAccount(int id, int initialDeposit = 0) {
        if (isUniqueId(id)) {
            Account *newAccount = new Account(id, initialDeposit);
            clientAccounts.push_back(newAccount);
            liquidity += initialDeposit * 0.05; // Bank receives 5% of the initial deposit
        } else {
            std::cerr << "Account ID must be unique" << std::endl;
        }
    }

    void deleteAccount(int id) {
        for (std::vector<Account *>::iterator it = clientAccounts.begin(); it != clientAccounts.end(); ++it) {
            if ((*it)->getId() == id) {
                delete *it;
                clientAccounts.erase(it);
                return;
            }
        }
        std::cerr << "Account not found" << std::endl;
    }

    void depositToAccount(int id, int amount) {
        for (std::vector<Account *>::iterator it = clientAccounts.begin(); it != clientAccounts.end(); ++it) {
            if ((*it)->getId() == id) {
                (*it)->deposit(amount * 0.95); // 5% fee to the bank
                liquidity += amount * 0.05;
                return;
            }
        }
        std::cerr << "Account not found" << std::endl;
    }

    void withdrawFromAccount(int id, int amount) {
        for (std::vector<Account *>::iterator it = clientAccounts.begin(); it != clientAccounts.end(); ++it) {
            if ((*it)->getId() == id) {
                (*it)->withdraw(amount);
                return;
            }
        }
        std::cerr << "Account not found" << std::endl;
    }

    void giveLoan(int id, int amount) {
        if (amount <= liquidity) {
            for (std::vector<Account *>::iterator it = clientAccounts.begin(); it != clientAccounts.end(); ++it) {
                if ((*it)->getId() == id) {
                    (*it)->deposit(amount);
                    liquidity -= amount;
                    return;
                }
            }
            std::cerr << "Account not found" << std::endl;
        } else {
            std::cerr << "Insufficient bank funds" << std::endl;
        }
    }

    friend std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank) {
        p_os << "Bank information: " << std::endl;
        p_os << "Liquidity: " << p_bank.liquidity << std::endl;
        for (std::vector<Account *>::const_iterator it = p_bank.clientAccounts.begin(); it != p_bank.clientAccounts.end(); ++it) {
            p_os << **it << std::endl;
        }
        return p_os;
    }

    ~Bank() {
        for (std::vector<Account *>::iterator it = clientAccounts.begin(); it != clientAccounts.end(); ++it) {
            delete *it;
        }
    }
};

#endif