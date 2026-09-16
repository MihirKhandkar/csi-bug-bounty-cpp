#ifndef STATS_H
#define STATS_H

#include <vector>
#include "Transaction.h"

using namespace std;

class Stats {
public:
    static double computeTotalAmount(const vector<Transaction>& transactions);
    static double computeAverageAmount(const vector<Transaction>& transactions);
    static void displaySummary(const vector<Transaction>& transactions, double currentBalance);
};

#endif
