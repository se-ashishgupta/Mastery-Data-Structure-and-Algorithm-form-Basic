#include <iostream>
using namespace std;

int gcdNaive(int a, int b) // O(min(a,b))
{
    int m = min(a, b);

    while (m > 0)
    {
        if (a % m == 0 && b % m == 0)
        {
            break;
        }
        m--;
    }

    return m;
}

// Euclied Algorithm
// hcf(a,b) = hcf(a-b, b) a > b
int gcdBetter(int a, int b) // O(min(a,b))
{
    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }

    return a;
}
int gcdBetter1(int a, int b) // O(min(a,b))
{
    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }

    if (a == 0)
        return b;

    return a;
}

// Optimal
int gcdOptimal(int a, int b) // O(log(min(a,b)))
{

    if (b == 0)
        return a;
    else
        return gcdOptimal(b, a % b);
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << gcdOptimal(a, b);
    return 0;
}