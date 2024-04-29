#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, int> freqMap = {
        {'a', 45},
        {'b', 13},
        {'c', 12},
        {'d', 16},
        {'e', 9},
        {'f', 5}
    };

    int totalCharacters = 0;
    for (const auto& entry : freqMap) {
        totalCharacters += entry.second;
    }


    int fixedBits = 4;


    cout << "Fixed-Length Codes:" << endl;
    for (const auto& entry : freqMap) {
        char character = entry.first;
        int frequency = entry.second;
        int bitsRequired = fixedBits * frequency;
        cout << character << ": " << bitsRequired << " bits" << endl;
    }

    return 0;
}
