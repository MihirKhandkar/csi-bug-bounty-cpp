#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

// Represents the wallet's account holder and handles simple
// username/password based login checks.
class User {
public:
    User(const string& username, const string& password);
    ~User();

    string getUsername() const;
    bool checkPassword(const string& inputPassword) const;

private:
    string username_;
    char* passwordHash_;
};

#endif
