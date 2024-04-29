#include <iostream>
using namespace std;

int main() 
{
    int first = 1; 
    int second = 2; 
    int next;
    int targetHouse = 18;

    cout << "First 20 house numbers:" << endl;
    cout << first << " "; 
    cout << second << " "; 

    
    for (int i = 3; i <= 20; i++) 
    {
        next = first + second;
        cout << next << " ";
        first = second;
        second = next;
    }

    cout << "\nFinding the 18th house number:" << endl;
    first = 1;
    second = 2;
    for (int i = 3; i <= targetHouse; i++) 
    {
        next = first + second;
        first = second;
        second = next;
    }
    cout << "The house number of the 18th house is: " << next << endl;

    return 0;
}
