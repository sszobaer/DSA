#include<bits/stdc++.h>
using namespace std;

void payWithLeastNotes(int amount, const int notes[], int size) 
{
    int noteCount[size] = {0};

    for (int i = 0; i < size; ++i) 
    {
        noteCount[i] = amount / notes[i];
        amount -= noteCount[i] * notes[i];
    }

    cout << "To pay back " << amount << " taka, you need the following notes:\n";
    for (int i = 0; i < size; i++) 
    {
        if (noteCount[i] > 0) 
        {
            cout << noteCount[i] << " notes of " << notes[i] << " taka\n";
        }
    }
}

int main() 
{
    int amount = 2887;
    int notes[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2};
    int size = sizeof(notes) / sizeof(notes[0]);
    payWithLeastNotes(amount, notes, size);
    return 0;
}
