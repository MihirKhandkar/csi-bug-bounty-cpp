#include <iostream>
#include <string>
#include "User.h"
#include "Wallet.h"
#include "Menu.h"

using namespace std;

int main() {
    cout << "Digital Wallet Login" << endl;

    string username, password;
    cout << "Set up username: ";
    cin >> username;
    cout << "Set up password: ";
    cin >> password;

    User* currentUser = new User(username, password);

    string loginUsername, loginPassword;
    cout << "\nRe-enter username to login: ";
    cin >> loginUsername;
    cout << "Re-enter password to login: ";
    cin >> loginPassword;

    if (loginUsername != currentUser->getUsername() || !currentUser->checkPassword(loginPassword)) {
        cout << "Login failed. Exiting." << endl;
        return 1;
    }

    cout << "\nLogin successful. Welcome, " << currentUser->getUsername() << "!" << endl;

    Wallet* wallet = new Wallet(0.0);
    Menu menu(*wallet, *currentUser);
    menu.run();

    return 0;
}
