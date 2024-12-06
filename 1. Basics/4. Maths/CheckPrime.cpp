#include <iostream>
#include <math.h>
using namespace std;

bool checkPrimeNaive(int a) // O(n)
{

    if (a == 0 || a == 1)
    {
        return false;
    }

    for (int i = 2; i < a; i++)
    {
        if (a % i == 0)
            return false;
    }

    return true;
}

// We can optimise the algorithm by only iterating up to the square root of n when checking for factors. This is because if n has a factor greater than its square root, it must also have a factor smaller than its square root.
bool checkPrimeEfficient(int a) // O(underrot(n))
{

    if (a == 0 || a == 1)
    {
        return false;
    }

    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
            return false;
    }

    return true;
}

bool checkPrimeEfficient1(int a) // O(underrot(n))
{

    int count = 0;

    for (int i = 1; i <= sqrt(a); i++)
    {
        if (a % i == 0)
        {
            count++;

            if (a / i != i)
            {
                count++;
            }
        }
    }

    return count == 2 ? true : false;
}

bool checkPrimeOptimal(int a) // faster than O(underrot(n))
{

    if (a == 0 || a == 1)
        return false;

    if (a == 2 || a == 3)
        return true;

    if (a % 2 == 0 || a % 3 == 0)
        return false;

    for (int i = 5; i * i <= a; i = i + 6)
    {
        if (a % i == 0 || a % (i + 2) == 0)
            return false;
    }

    return true;
}

int main()
{
    cout << checkPrimeEfficient1(17);
    return 0;
}