#include <iostream>

using namespace std;

int main() 
{
    int startYear, endYear;

    // Input
    cout << "Enter the start year: ";
    cin >> startYear;

    cout << "Enter the end year: ";
    cin >> endYear;

    // Display leap years 
    bool foundLeapYear = false;
    cout << "Leap years between " << startYear << " and " << endYear << ": ";

    for (int year = startYear; year <= endYear; year++) 
    {
        // Check if the year is a leap year
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) 
        {
            cout << year << " ";
            foundLeapYear = true;
        }
    }

    if (!foundLeapYear) 
    {
        cout << "No leap years found.";
    }

    cout << endl;

    return 0;
}
