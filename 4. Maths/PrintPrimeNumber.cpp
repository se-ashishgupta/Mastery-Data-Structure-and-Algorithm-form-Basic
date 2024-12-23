#include <iostream>
#include <vector>
using namespace std;

bool checkPrime(int n) // O(sqrt(n))
{

    int count = 0;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;

            if (n / i != i)
            {
                count++;
            }
        }
    }

    return count == 2;
}

void printPrimeNumberNaive(int n)
{

    for (int i = 1; i <= n; i++)
    {
        if (checkPrime(i))
        {
            cout << i << " ";
        }
    }
}

void printPrimeNumberEfficient(int n) // O(nlog(log(n)))
{

    vector<int> isPrime(n + 1, true);

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = 2 * i; j <= n; j = j + i)
            {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            cout << i << " ";
        }
    }
}

void printPrimeNumberOptimized(int n) // O(nlog(log(n)))
{

    vector<int> isPrime(n + 1, true);

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j = j + i)
            {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            cout << i << " ";
        }
    }
}

void printPrimeNumberOptimizedSoter(int n) // O(nlog(log(n)))
{

    vector<int> isPrime(n + 1, true);

    for (int i = 2; i <= n; i++) //   // O(n)
    {
        if (isPrime[i])
        {
            cout << i << " ";
            for (int j = i * i; j <= n; j = j + i) // O(log(log(n)))
            {
                isPrime[j] = false;
            }
        }
    }
}

// O(n*sqrt(n))
int main()
{

    printPrimeNumberOptimizedSoter(23);
    return 0;
}