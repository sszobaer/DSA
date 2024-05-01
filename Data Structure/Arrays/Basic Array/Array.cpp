#include <iostream>

using namespace std;

int main()
{
    //Declaire an array
    int arr[10];

    //Display for user
    cout<<"Enter 10 numbers : "<<endl;

    //loop for user input
    for(int i=0 ; i<10 ; i++)
        cin>> arr[i];

    //For output
    for (int n=0 ; n<10 ; n++)
        cout<< arr[n]<<" ";

    return 0;
}
