#ifndef FILE_STORAGE_H
#define FILE_STORAGE_H

#include <string>
#include <vector>
#include "Transaction.h"

using namespace std;

class FileStorage {
public:
    static void saveTransactions(const string& filename, const vector<Transaction>& transactions);
    static vector<Transaction> loadTransactions(const string& filename);
};

#endif
