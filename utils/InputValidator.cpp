#include "InputValidator.h"

using namespace std;

bool InputValidator::isNumeric(const string& input) {
    if (input.empty()) {
        return false;
    }

    for (size_t i = 0; i < input.size(); ++i) {
        if (!isdigit(static_cast<unsigned char>(input[i]))) {
            return false;
        }
    }
    return true;
}

bool InputValidator::isValidMenuChoice(int choice) {
    return choice >= 1 && choice <= 5;
}
