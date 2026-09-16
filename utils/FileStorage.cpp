#include "FileStorage.h"
#include <fstream>
#include <cstring>
#include <iostream>

using namespace std;

void FileStorage::saveTransactions(const string& filename, const vector<Transaction>& transactions) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Could not open file for saving." << endl;
        return;
    }

    for (const auto& txn : transactions) {
        string typeStr = (txn.getType() == TransactionType::CREDIT) ? "CREDIT" : "DEBIT";
        string formatted = to_string(txn.getId()) + "," + typeStr + "," +
                                 to_string(txn.getAmount()) + "," + txn.getDescription();
        outFile << formatted << endl;
    }

    outFile.close();
}

vector<Transaction> FileStorage::loadTransactions(const string& filename) {
    vector<Transaction> transactions;
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        return transactions;
    }

    string line;
    while (getline(inFile, line)) {
        // Parsing intentionally omitted for this simplified demo storage layer.
    }

    inFile.close();
    return transactions;
}
