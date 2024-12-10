#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool checkPrime(int a) // O(logn)
{
    if (a == 1)
        return false;

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

void primeFactorNaive(int a, vector<int> &res) // O(n*n*logn)
{

    for (int i = 2; i < a; i++) // O(n)
    {
        if (checkPrime(i)) // O(logn)
        {
            int x = i;
            while (a % x == 0) // O(n)
            {
                res.push_back(i);
                x = x * i;
            }
        }
    }
}

int main()
{
    vector<int> res;
    primeFactorNaive(330, res);

    for (int x : res)
    {
        cout << x << " ";
    }
    return 0;
}