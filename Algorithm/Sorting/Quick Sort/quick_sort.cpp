#include <iostream>
using namespace std;

// partition & pivot
int partition(int arr[], int low, int high) 
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

//  implementation of sorting
void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pivotIndex = partition(arr, low, high);

        // Recursion for sub array
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

//  print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Example usage
    int arr[] = {13,12,4,5,3,0,1};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array: ";
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
