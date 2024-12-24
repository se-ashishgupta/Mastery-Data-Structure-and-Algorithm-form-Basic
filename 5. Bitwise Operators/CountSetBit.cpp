#include <iostream>
using namespace std;

int countSetBit(int n) // O(Total Bits in n)
{
    int res = 0;

    while (n != 0)
    {
        // if (n % 2 != 0)
        if (n & 1 == 1)
        {
            res++;
        }

        // n = n >> 1;
        n = n / 2;
    }

    return res;
}

// Brian kerningam's Algorithm
int countSetBit1(int n) // O(Total Bits in n)
{
    int res = 0;

    while (n > 0)
    {
        n = n & (n - 1);
        res++;
    }

    return res;
}

int main()
{

    cout << countSetBit1(7);

    return 0;
}