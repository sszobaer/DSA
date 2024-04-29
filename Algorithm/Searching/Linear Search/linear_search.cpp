#include<iostream>
using namespace std;

int main()
{
    string refrigerator[3][3]={{"Eggs", "Cheese","fruits"},{"Orange","Onion", "Tomatoes"},{"Cucumber", "Milk","Apple"}};

    bool foundTomatoes = false;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if (refrigerator[i][j]=="Tomatoes")
            {
                foundTomatoes = true;
                break;
            }
        }
        if(foundTomatoes)
        {
            break;
        }   
    }
    if(foundTomatoes)
    {
        cout<<"Tomatoes are found"<<endl;
    }
    else
    {
        cout<<"tomatoes are not found"<<endl;
    }
    
    return 0;

}