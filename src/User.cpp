#include "User.h"
#include <cstring>

using namespace std;

User::User(const string& username, const string& password)
    : username_(username) {
    passwordHash_ = new char[password.size()];
    strcpy(passwordHash_, password.c_str());
}

User::~User() {
    delete[] passwordHash_;
}

string User::getUsername() const {
    return username_;
}

bool User::checkPassword(const string& inputPassword) const {
    return inputPassword == passwordHash_;
}
