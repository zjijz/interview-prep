#include <iostream>

const static char charValueZero = 48;
static bool available[10][10] = {
        {true, false, false, false, false, false, false, false, false, false},
        {true, true, true, true, true, true, true, true, true, true},
        {true, false, true, true, false, true, true, false, true, true},
        {false, false, false, true, false, false, true, false, false, true},
        {true, false, false, false, true, true, true, true, true, true},
        {true, false, false, false, false, true, true, false, true, true},
        {false, false, false, false, false, false, true, false, false, true},
        {true, false, false, false, false, false, false, true, true, true},
        {true, false, false, false, false, false, false, false, true, true},
        {false, false, false, false, false, false, false, false, false, true}
};

std::string closest(int num) {
    for (int i = 0; i <= num; i++) {
        std::string p = std::to_string(num + i);
        std::string n = std::to_string(num - i);

        for (int j = 0; j < 2; j++) {
            std::string s = (j == 0 ? p : n);
            for (int k = 0; k < s.length(); k++) {
                if (k == s.length() - 1) return s;

                char c = s[k] - charValueZero;
                char nextC = s[k + 1] - charValueZero;
                if (!available[c][nextC]) break;
            }
        }
    }
}

int main() {
    int numCases;
    std::cin >> numCases;
    for (int i = 0; i < numCases; i++) {
        int input;
        std::cin >> input;
        std::cout << closest(input) << std::endl;
    }
    return 0;
}