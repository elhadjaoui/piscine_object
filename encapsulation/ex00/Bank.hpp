#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <vector>
#include "Account.hpp"

class Bank {
private:
    int liquidity;
    std::vector<Account *> clientAccounts;
    static const int BANK_FEE_RATE = 5; // 5% fee

    bool isUniqueId(int id) const {
        for (std::vector<Account *>::const_iterator it = clientAccounts.begin(); it != clientAccounts.end(); ++it) {
            if ((*it)->getId() == id) {
                return false;
            }
        }
        return true;
    }

    Account* findAccount(int id) const {
        for (std::vector<Account *>::const_iterator it = clientAccounts.begin(); it != clientAccounts.end(); ++it) {
            if ((*it)->getId() == id) {
                return *it;
            }
        }
        return NULL; 
    }

public:
    Bank() : liquidity(0) {}

    int getLiquidity() const {
        return liquidity;
    }

    bool createAccount(int id, int initialDeposit = 0) {
        if (!isUniqueId(id)) {
            std::cerr << "Error: Account ID must be unique" << std::endl;
            return false;
        }
        
        int bankFee = static_cast<int>(initialDeposit * BANK_FEE_RATE / 100);
        int accountAmount = initialDeposit - bankFee;
        
        Account *newAccount = new Account(id, accountAmount);
        clientAccounts.push_back(newAccount);
        liquidity += bankFee;
        return true;
    }

    bool deleteAccount(int id) {
        for (std::vector<Account *>::iterator it = clientAccounts.begin(); it != clientAccounts.end(); ++it) {
            if ((*it)->getId() == id) {
                delete *it;
                clientAccounts.erase(it);
                return true;
            }
        }
        std::cerr << "Error: Account not found" << std::endl;
        return false;
    }

    bool depositToAccount(int id, int amount) {
        Account* account = findAccount(id);
        if (!account) {
            std::cerr << "Error: Account not found" << std::endl;
            return false;
        }
        
        int bankFee = static_cast<int>(amount * BANK_FEE_RATE / 100);
        int accountAmount = amount - bankFee;
        
        account->deposit(accountAmount);
        liquidity += bankFee;
        return true;
    }

    bool withdrawFromAccount(int id, int amount) {
        Account* account = findAccount(id);
        if (!account) {
            std::cerr << "Error: Account not found" << std::endl;
            return false;
        }
        
        if (account->getValue() < amount) {
            std::cerr << "Error: Insufficient funds" << std::endl;
            return false;
        }
        
        account->withdraw(amount);
        return true;
    }

    bool giveLoan(int id, int amount) {
        if (amount > liquidity) {
            std::cerr << "Error: Insufficient bank funds" << std::endl;
            return false;
        }
        
        Account* account = findAccount(id);
        if (!account) {
            std::cerr << "Error: Account not found" << std::endl;
            return false;
        }
        
        account->deposit(amount);
        liquidity -= amount;
        return true;
    }

    const std::vector<Account *>& getClientAccounts() const {
        return clientAccounts;
    }

    friend std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank) {
        p_os << "Bank information: " << std::endl;
        p_os << "Liquidity: " << p_bank.liquidity << std::endl;
        for (std::vector<Account *>::const_iterator it = p_bank.clientAccounts.begin();
             it != p_bank.clientAccounts.end(); ++it) {
            p_os << **it << std::endl;
        }
        return p_os;
    }

    ~Bank() {
        for (std::vector<Account *>::iterator it = clientAccounts.begin(); it != clientAccounts.end(); ++it) {
            delete *it;
        }
        clientAccounts.clear(); 
    }
};

#endif