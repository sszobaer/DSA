#include <iostream>

using namespace std;

bool isPrime(int num)
{
    if (num <= 1)
    {
        return false; // 0 and 1 are not prime numbers
    }

    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
        {
            return false; // If the number is divisible by any integer between 2 and sqrtNum, it's not prime
        }
    }

    return true;
}

int main()
{
    const int size = 5;
    int numbers[size] = {1,2,4,23,59};

    cout << "Numbers in the array:" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    cout << "Prime numbers in the array:" << endl;
    for (int i = 0; i < size; ++i)
    {
        if (isPrime(numbers[i]))
        {
            cout << numbers[i] << " ";
        }
    }

    cout << endl;

    return 0;
}
