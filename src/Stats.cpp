#include "Stats.h"
#include <iostream>

using namespace std;

double Stats::computeTotalAmount(const vector<Transaction>& transactions) {
    double total = 0.0;
    for (const auto& txn : transactions) {
        if (txn.getType() == TransactionType::CREDIT) {
            total += txn.getAmount();
        } else {
            total -= txn.getAmount();
        }
    }
    return total;
}

double Stats::computeAverageAmount(const vector<Transaction>& transactions) {
    double total = 0.0;
    for (const auto& txn : transactions) {
        total += txn.getAmount();
    }
    return total / transactions.size();
}

void Stats::displaySummary(const vector<Transaction>& transactions, double currentBalance) {
    cout << "----- Wallet Statistics -----" << endl;
    cout << "Total transactions : " << transactions.size() << endl;
    cout << "Net total          : " << computeTotalAmount(transactions) << endl;
    cout << "Average amount     : " << computeAverageAmount(transactions) << endl;
    cout << "Current balance    : " << currentBalance << endl;
}
