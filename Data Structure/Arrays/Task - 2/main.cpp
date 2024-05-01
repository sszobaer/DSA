#include <iostream>

using namespace std;

int main()
{
    int arr[5];

//Display this for user
cout<<"Enter 5 numbers : ";

//Take input from user
for (int i=0 ; i<5 ; i++)
    cin>> arr[i];

    //Display the numbers
cout<<"The numbers are : ";

//final loop for display this array elements
for (int n=0 ; n<5 ;n++)
    cout<<arr[n]<< " " ;

    return 0;
}
