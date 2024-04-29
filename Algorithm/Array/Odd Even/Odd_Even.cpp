#include <iostream>

using namespace std;

int main() {
    const int size = 20;
    int inputArray[size] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

    cout << "Odd numbers: ";
    for (int i = 0; i < size; ++i) {
        if (inputArray[i] % 2 != 0) {
            cout << inputArray[i] << " ";
        }
    }

    cout << "\nEven numbers: ";
    for (int i = 0; i < size; ++i) {
        if (inputArray[i] % 2 == 0) {
            cout << inputArray[i] << " ";
        }
    }

    cout << endl;

    return 0;
}
