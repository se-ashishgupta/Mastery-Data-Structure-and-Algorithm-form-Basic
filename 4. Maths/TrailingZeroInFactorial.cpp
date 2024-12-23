#include <iostream>
using namespace std;

// This solution cause overflow for large value of n
int TrailingZeroInFactorialNaive(int n)
{

    int f = 1;
    for (int i = 2; i <= n; i++)
    {
        f *= i;
    }

    int res = 0;
    while (f % 10 == 0)
    {
        res++;
        f = f / 10;
    }

    return res;
}

// Here 0 will come after multiplication of 2 and 5 so we count all 2 and 5 in factors of n and take the min(2, 5) counts but we see always 2 is less or equal to 5 so just count 5 in factor.
// but in no like 28 one extra 5 is there so to deal with this first divide by 5 to remove all single 5s then divide by 25 to deal extra 5 and so on
// Trailing 0s in n! = Count of 5s in prime factors of n! = floor(n/5) + floor(n/25) + floor(n/125) + …

int TrailingZeroInFactorial(int n)
{
    int res = 0;
    for (int i = 5; i <= n; i = i * 5)
    {
        res += n / i;
    }
    return res;
}

int main()
{
    cout << TrailingZeroInFactorial(25);

    return 0;
}
