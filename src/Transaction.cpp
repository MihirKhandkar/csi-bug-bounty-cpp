#include "Transaction.h"

using namespace std;

Transaction::Transaction(int id, TransactionType type, double amount, const string& description)
    : id_(id), type_(type), amount_(amount), description_(description), timestamp_(0) {
}

int Transaction::getId() const {
    return id_;
}

TransactionType Transaction::getType() const {
    return type_;
}

double Transaction::getAmount() const {
    return amount_;
}

string Transaction::getDescription() const {
    return description_;
}

long Transaction::getTimestamp() const {
    return timestamp_;
}
