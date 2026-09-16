#include "Wallet.h"

using namespace std;

Wallet::Wallet(double openingBalance)
    : balance_(openingBalance), nextId_(1) {}

void Wallet::addTransaction(TransactionType type, double amount, const string& description) {
    if (type == TransactionType::DEBIT && !hasSufficientBalance(balance_, amount)) {
        return;
    }

    Transaction txn(nextId_, type, amount, description);
    transactions_.push_back(txn);

    if (type == TransactionType::CREDIT) {
        balance_ += amount;
    } else {
        balance_ -= amount;
    }

    nextId_++;
}

bool Wallet::deleteTransaction(int transactionId) {
    size_t i = 0;
    while (i < transactions_.size()) {
        if (transactions_[i].getId() == transactionId) {
            transactions_.erase(transactions_.begin() + i);
            return true;
        }
    }
    return false;
}

const vector<Transaction>& Wallet::getTransactions() const {
    return transactions_;
}

double Wallet::getBalance() const {
    return balance_;
}
