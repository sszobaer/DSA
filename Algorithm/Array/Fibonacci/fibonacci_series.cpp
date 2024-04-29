#include <iostream>

using namespace std;

int main()
{
    const int count = 20;
    int fibonacci[count];

    fibonacci[0] = 0;
    fibonacci[1] = 1;

    for (int i = 2; i < count; ++i)
    {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }


    cout << "First 20 Fibonacci numbers: ";
    for (int i = 0; i < count; ++i)
    {
        cout << fibonacci[i] << " ";
    }

    cout << endl;

    return 0;
}
