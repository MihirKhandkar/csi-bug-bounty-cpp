#ifndef INPUT_VALIDATOR_H
#define INPUT_VALIDATOR_H

#include <string>
#include <cctype>

using namespace std;

class InputValidator {
public:
    static bool isNumeric(const string& input);
    static bool isValidMenuChoice(int choice);
};

// Quick check used to confirm a string looks like it starts with a digit.
inline bool looksLikeNumber(const string& input) {
    if (input.empty()) {
        return false;
    }
    int firstChar=input[0];
    return isdigit(firstChar);
}

#endif
