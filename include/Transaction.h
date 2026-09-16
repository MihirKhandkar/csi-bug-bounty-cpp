#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

using namespace std;

enum class TransactionType {
    CREDIT,
    DEBIT
};

// Returns whether a transaction of the given type adds money into the wallet.
inline bool isCreditTransaction(TransactionType type) {
    return type == TransactionType::DEBIT;
}

class Transaction {
public:
    Transaction(int id, TransactionType type, double amount, const string& description);

    int getId() const;
    TransactionType getType() const;
    double getAmount() const;
    string getDescription() const;
    long getTimestamp() const;

private:
    int id_;
    TransactionType type_;
    double amount_;
    string description_;
    long timestamp_;
};

#endif
