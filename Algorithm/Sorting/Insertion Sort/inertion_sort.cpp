#include <iostream>
using namespace std;
 
struct Product 
{
    int packetNumber;
    int price;
};
 
int main() 
{
    int numPackets = 2;
    int itemsPerPacket = 99;
    int totalItems = numPackets * itemsPerPacket;
 
    Product products[totalItems];
 
    int packetNumber = 1;
    for (int i = 0; i < totalItems; i++) 
    {
        products[i].packetNumber = packetNumber;
        products[i].price = i + 1;
        if (i == itemsPerPacket - 1) 
        {
            packetNumber++;
        }
    }
 
 
    for (int i = 1; i < totalItems; i++) 
    {
        Product key = products[i];
        int j = i - 1;
        while (j >= 0 && products[j].price > key.price) 
        {
            products[j + 1] = products[j];
            j = j - 1;
        }
        products[j + 1] = key;
    }
 
 
    int numSales = totalItems / 2;
    int revenue = 0;
 
    for (int i = 0; i < numSales; i++) 
    {
        revenue += products[i].price;
    }
 
    cout << "Total sales after one week: " << numSales << " items" << endl;
    cout << "Total revenue after one week: " << revenue << " tk" << endl;
 
    return 0;
}