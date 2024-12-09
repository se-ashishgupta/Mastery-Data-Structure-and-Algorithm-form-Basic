#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void primeFactorNaive(int a, vector<int> &res) // O(n)
{

    int i = 2;

    while (a > 1)
    {
        if (a % i == 0)
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
    primeFactorNaive(15, res);

    for (int x : res)
    {
        cout << x << " ";
    }
    return 0;
}