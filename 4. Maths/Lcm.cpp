#include <iostream>
using namespace std;

int lcmNaive(int a, int b) // O(min(a,b))
{
    int m = max(a, b);

    while (true)
    {
        if (m % a == 0 && m % b == 0)
        {
            break;
        }
        m++;
    }

    return m;
}

// Euclied Algorithm
// hcf(a,b) = hcf(a-b, b) a > b

// Optimal
int gcdOptimal(int a, int b) // O(log(min(a,b)))
{

    if (b == 0)
        return a;
    else
        return gcdOptimal(b, a % b);
}

int lcmOptimal(int a, int b)
{

    int gcd = gcdOptimal(a, b);
    return (a * b) / gcd;
}

int main()
{
    int a = 20, b = 15;
    cout << lcmOptimal(a, b);
    return 0;
}