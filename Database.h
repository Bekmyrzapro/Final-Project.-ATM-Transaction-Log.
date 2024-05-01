#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>  // Include for timestamp functionality

struct Transaction {
    int id;
    std::string type;
    double amount;
    std::string timestamp;

    Transaction(int id, std::string type, double amount, std::string timestamp)
        : id(id), type(type), amount(amount), timestamp(timestamp) {}
};

class Database {
private:
    std::vector<Transaction> transactions;
    std::string filename;
    int nextID = 1;  // Initialize ID to start from 1

    void loadTransactions();
    void saveTransactions();
    std::string getCurrentTimestamp();  // For automatic timestamp generation

public:
    Database(const std::string &filename);
    ~Database();

    void addTransaction(const std::string& type, double amount);
    void displayTransactions();
    void updateTransaction(int id, const std::string& type, double amount);
    void deleteTransaction(int id);
};

#endif
