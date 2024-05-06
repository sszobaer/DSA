// Task: Perform a Insertion sort method to sort 92, 82, 21, 16, 18, 95 this values
#include <iostream>
using namespace std;

void insertionSort(int arr[], int size, int& comparisons, int& shifts) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            shifts++;
            j--;
        }

        arr[j + 1] = key;
        shifts++;
    }
}

int main() {
    int arr[] = {92, 82, 21, 16, 18, 95};
    int size = sizeof(arr) / sizeof(arr[0]);
    int comparisons = 0;
    int shifts = 0;

    cout << "Input: [";
    for (int i = 0; i < size; ++i) {
        cout << arr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    insertionSort(arr, size, comparisons, shifts);

    cout << "Output: [";
    for (int i = 0; i < size; ++i) {
        cout << arr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout << "Number of comparisons = " << comparisons << endl;
    cout << "Number of shifts = " << shifts << endl;

    return 0;
}
