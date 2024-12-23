
#include <bits/stdc++.h>
using namespace std;

void allDivisorNaive(int n, vector<int> &res) // Takes O(n) time
{
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            res.push_back(i);
        }
    }
}

void allDivisor(int n, vector<int> &res) // Takes O(sqrt(n)) time but not in sorted order
{
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            res.push_back(i);
            if (n / i != i)
            {
                res.push_back(n / i);
            }
        }
    }
}
void allDivisorSorted(int n, vector<int> &res) // Takes O(sqrt(n)) time but not in sorted order
{

    int i;
    for (i = 1; i * i < n; i++)
    {
        if (n % i == 0)
        {
            res.push_back(i);
        }
    }
    for (; i >= 1; i--)
    {
        if (n % i == 0)
        {

            res.push_back(n / i);
        }
    }
}

int main()
{
    vector<int> res;
    allDivisorSorted(15, res);
    // sort(res.begin(), res.end());

    for (int x : res)
    {
        cout << x << " ";
    }

    return 0;
}