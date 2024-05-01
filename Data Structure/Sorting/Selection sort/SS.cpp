#include <iostream>

using namespace std;

void selectionSort(int arr[], int size, int& comparisons, int& exchanges) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;

        for (int j = i + 1; j < size; ++j) {
            comparisons++;

            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            exchanges++;
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

    selectionSort(arr, size, comparisons, exchanges);

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
