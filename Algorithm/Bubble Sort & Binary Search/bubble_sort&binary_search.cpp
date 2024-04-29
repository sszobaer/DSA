#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int l, int r, int key) 
{
    while (l <= r) 
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            l = mid + 1;

        else
            r = mid - 1;
    }

    return -1;
}

int main() 
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int key;
    cout << "Enter the element to search: ";
    cin >> key;
    int result = binarySearch(arr, 0, n - 1, key);
    if (result == -1)
        cout << "Element not found";
    else
        cout << "Element found at index " << result;

    return 0;
}
