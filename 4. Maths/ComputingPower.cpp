#include <iostream>
using namespace std;

int computePowerIterative1(int x, int n) // O(n)
{

    int res = 1;

    for (int i = 1; i <= n; i++)
    {
        res = res * x;
    }

    return res;
}

int computePowerRecursive1(int x, int n) // O(logn)
{

    if (n == 0)
        return 1;

    int temp = computePowerRecursive1(x, n / 2);
    temp = temp * temp;
    if (n % 2 == 0)
    {
        return temp;
    }
    else
    {
        return temp * x;
    }
}

// Binary Exponentiation
int computePoweriIterative2(int x, int n) // O(logn)
{
    int res = 1;

    while (n > 0)
    {
        if (n % 2 != 0)
            res = res * x;
        x = x * x;
        n = n / 2;
    }
    return res;
}

int computePowerRecursive2(int x, int n) // O(logn)
{

    if (n == 0)
        return 1;

    if (n % 2 == 0)
    {
        return computePowerRecursive2(x * x, n / 2);
    }
    else
    {
        return x * computePowerRecursive2(x * x, (n - 1) / 2);
    }
}

int main()
{

    cout << computePoweriIterative2(2, 4);
    return 0;
}