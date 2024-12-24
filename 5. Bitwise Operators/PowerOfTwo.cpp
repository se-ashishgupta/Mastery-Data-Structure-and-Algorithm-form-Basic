#include <iostream>
using namespace std;

bool powerOfTwoNaive(int n) // O(1)
{
    if (n == 0)
        return false;

    while (n != 0)
    {

        if (n % 2 != 0)
            return false;

        n = n / 2;
    }

    return true;
}

// Hint: Having single SetBit
bool powerOfTwo(int n) // O(1)
{

    if (n == 0)
        return false;
    return (n & (n - 1)) == 0;
}

int main()
{

    cout << powerOfTwo(6);

    return 0;
}