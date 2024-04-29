#include <bits/stdc++.h>
using namespace std;

// Sorting Algorithms
void quickSort(vector<int>& arr, int low, int high);
void mergeSort(vector<int>& arr, int low, int high);
void insertionSort(vector<int>& arr);

// Searching Algorithms
int linearSearch(const vector<int>& arr, int target);
int binarySearch(const vector<int>& arr, int target);

// Utility function to print an array
void printArray(const vector<int>& arr);

int main() 
{
    // Input array
    vector<int> arr = {56, 23, 78, 12, 45, 89, 34, 67};

    // Sorting options
    cout << "Choose a sorting algorithm:" << endl;
    cout << "1. Quick Sort\n2. Merge Sort\n3. Insertion Sort\n";
    int sortingChoice;
    cin >> sortingChoice;

    switch (sortingChoice) 
    {
        case 1:
            quickSort(arr, 0, arr.size() - 1);
            break;
        case 2:
            mergeSort(arr, 0, arr.size() - 1);
            break;
        case 3:
            insertionSort(arr);
            break;
        default:
            cout << "Invalid sorting choice. Exiting program." << endl;
            return 1;
    }

    cout << "Sorted Array: ";
    printArray(arr);

    // Searching options
    cout << "Choose a searching algorithm:" << endl;
    cout << "1. Linear Search\n2. Binary Search\n";
    int searchingChoice;
    cin >> searchingChoice;

    int target;
    cout << "Enter the target value to search: ";
    cin >> target;

    int index = -1; // Default value if not found

    switch (searchingChoice) 
    {
        case 1:
            index = linearSearch(arr, target);
            break;
        case 2:
            index = binarySearch(arr, target);
            break;
        default:
            cout << "Invalid searching choice. Exiting program." << endl;
            return 1;
    }

    if (index != -1) 
    {
        cout << "Target found at index " << index << endl;
    } 
    else 
    {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}

// Sorting Algorithms
void quickSort(vector<int>& arr, int low, int high) 
{
    
}

void mergeSort(vector<int>& arr, int low, int high) 
{
    
}

void insertionSort(vector<int>& arr) 
{
    
}

// Searching Algorithms
int linearSearch(const vector<int>& arr, int target) 
{
    // Implement Linear Search
    for (int i = 0; i < arr.size(); ++i) 
    {
        if (arr[i] == target) 
        {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

int binarySearch(const vector<int>& arr, int target) 
{
    // Implement Binary Search (Assumes array is sorted)
    int low = 0, high = arr.size() - 1;

    while (low <= high) 
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) 
        {
            return mid; // Return index if found
        } 
        else if (arr[mid] < target) 
        {
            low = mid + 1;
        } 
        else 
        {
            high = mid - 1;
        }
    }

    return -1; // Return -1 if not found
}

// Utility function to print an array
void printArray(const vector<int>& arr) 
{
    for (int num : arr) 
    {
        cout << num << " ";
    }
    cout << endl;
}
