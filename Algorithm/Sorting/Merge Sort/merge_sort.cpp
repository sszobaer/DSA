#include <iostream>
using namespace std;


void merge(int arr[], int l, int m, int r) 
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to this array
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge
    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any element
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any element
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// MergeSort function
void mergeSort(int arr[], int l, int r) 
{
    if (l < r) 
    {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

// Utility function to print an array
void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() 
{
    // Example usage
    int arr[] = {13,12,4,5,3,0,1};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array: ";
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
