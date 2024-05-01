#include <bits/stdc++.h>
using namespace std;

int main()
{
  double num[]= {7,5,6,12,35,27};
  double sum=0;
  double count=0;
  double avg=0;

  cout<<"The numbers are : ";

  for(int i=0 ; i<6 ; i++){
    cout<<num[i]<<endl;
    sum+=num[i];
    count++;
  }

  cout<<"Their sum = "<<sum<<endl;
  avg = sum/count;
  cout<<"Their avarage = "<<avg<<endl;

  return 0;
}
