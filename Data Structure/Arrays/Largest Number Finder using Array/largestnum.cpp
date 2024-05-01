#include <bits/stdc++.h>
using namespace std;

void thirdLargest(int arr[], int arr_size)
{

    if (arr_size < 3)
    {
        cout<<" Invalid Input ";
        return;
    }


    int first = arr[0];
    for (int i = 1; i < arr_size ; i++)
        if (arr[i] > first)
            first = arr[i];


    int second = INT_MIN;
    for (int i = 0; i < arr_size ; i++)
        if (arr[i] > second && arr[i] < first)
            second = arr[i];

    int third = INT_MIN;
    for (int i = 0; i < arr_size ; i++)
        if (arr[i] > third && arr[i] < second)
            third = arr[i];

    cout<<"The third Largest element is : "<<third;
}


int main()
{
    int arr[] = {28, 13, 19, 50, 34, 16};
    int n = sizeof(arr)/sizeof(arr[0]);
    thirdLargest(arr, n);
    return 0;
}
