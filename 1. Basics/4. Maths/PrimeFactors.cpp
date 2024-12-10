#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool checkPrime(int a)
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

    for (int i = 2; i < a; i++)
    {
        if (checkPrime(i))
        {
            int x = i;
            while (a % x == 0)
            {
                res.push_back(i);
                x = x * i;
            }
        }
    }
}
void primeFactorNaive1(int a, vector<int> &res) // O(n*logn)
{

    int i = 2;
    while (a > 1)
    {
        if (a % i == 0 && checkPrime(i))
        {
            res.push_back(i);
            a = a / i;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    vector<int> res;
    primeFactorNaive(315, res);

    for (int x : res)
    {
        cout << x << " ";
    }
    return 0;
}