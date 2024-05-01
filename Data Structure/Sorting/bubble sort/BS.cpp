#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size, int& comparisons, int& exchanges) {
    bool swapped;

    for (int i = 0; i < size - 1; ++i) {
        swapped = false;

        for (int j = 0; j < size - i - 1; ++j) {
            comparisons++;

            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                exchanges++;
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

int main() {
    int arr[] = {92, 82, 21, 16, 18, 95};
    int size = sizeof(arr) / sizeof(arr[0]);
    int comparisons = 0;
    int exchanges = 0;

    cout << "Input: [";
    for (int i = 0; i < size; ++i) {
        cout << arr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    bubbleSort(arr, size, comparisons, exchanges);

    cout << "Output: [";
    for (int i = 0; i < size; ++i) {
        cout << arr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout << "Number of comparisons = " << comparisons << endl;
    cout << "Number of exchanges = " << exchanges << endl;

    return 0;
}
