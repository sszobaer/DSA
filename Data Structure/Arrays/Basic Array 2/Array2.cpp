#include <iostream>

using namespace std;

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,0};

    //Normal sequence
    cout<< "The numbers are in normal order : ";

    for (int i=0 ; i<10 ; i++)
        cout<< arr[i]<<" " ;

    //Reverse sequence
    cout<<"\n The numbers are in reverse order : ";

    for ( int i=9 ; i>=0 ;i--)
        cout<< arr[i]<<" ";

    return 0;
}
