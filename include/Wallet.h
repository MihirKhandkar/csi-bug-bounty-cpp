#ifndef WALLET_H
#define WALLET_H

#include <string>
#include <vector>
#include "Transaction.h"

using namespace std;

// Checks whether the wallet has enough balance to cover a debit of `amount`.
inline bool hasSufficientBalance(double balance, double amount) {
    return balance >= amount;
}

class Wallet {
public:
    explicit Wallet(double openingBalance);

    void addTransaction(TransactionType type, double amount, const string& description);
    bool deleteTransaction(int transactionId);
    const vector<Transaction>& getTransactions() const;
    double getBalance() const;

private:
    double balance_;
    vector<Transaction> transactions_;
    int nextId_;
};

#endif
