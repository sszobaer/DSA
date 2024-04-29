#include<iostream>
using namespace std;

struct Grocery
{
    int weight;
    int price;
};



int main()
{
    Grocery groceries[] = {
        {5, 450},  // rice
        {3, 240},  // salt
        {6, 660},  // sugar
        {5, 600}   // onion
 
    };
 
    int numOfGroceries = sizeof(groceries) / sizeof(groceries[0]);
 
    int bagCapacity = 14;
    int totalWeight = 0;
    int totalPrice = 0;
 
 
    for (int i = 0; i < numOfGroceries - 1; i++) 
    {
        for (int j = 0; j < numOfGroceries - i - 1; j++) 
        {
            if (groceries[j].price / groceries[j].weight > groceries[j + 1].price / groceries[j + 1].weight) 
            {
 
                Grocery temp = groceries[j];
                groceries[j] = groceries[j + 1];
                groceries[j + 1] = temp;
            }
        }
    }
 
    int notes[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int numNotes = 0;
 
    for (int i = 0; i < numOfGroceries; i++) 
    {
        while (totalWeight + groceries[i].weight <= bagCapacity) 
        {
            totalWeight += groceries[i].weight;
            totalPrice += groceries[i].price;
        }
    }
 
    cout << "Total price: " << totalPrice << " tk" << endl;
 
    for (int i = 0; i < sizeof(notes) / sizeof(notes[0]); i++) 
    {
        while (totalPrice >= notes[i]) 
        {
            numNotes++;
            totalPrice -= notes[i];
        }
    }
 
    cout << "Minimum number of notes: " << numNotes << endl;
 
    // Calculate revenue of the shopkeeper
    int revenue = 0;
    for (int i = 0; i < numOfGroceries; i++) 
    {
        revenue += groceries[i].price;
    }
 
    cout << "Shopkeeper's revenue: " << revenue << " tk" << endl;
 
    return 0;
}