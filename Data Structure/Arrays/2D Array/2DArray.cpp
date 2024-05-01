#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[16] = {1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6};
//int  arr [4][5]={}
    //Display the first row
    for( int i=0 ; i<4 ;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    cout<<endl;

    //Display the second row
    for (int i=4 ; i<8 ; i++)
        cout<< arr[i]<<" ";
    cout<<endl;
    cout<<endl;

    //Display the third row
    for (int i=8 ; i<12 ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    cout<<endl;

    //Display the fourth row
    for( int i=12 ; i<16 ; i++)
        cout<<arr[i]<< " ";
    cout<<endl;

    return 0;
}
