#include <iostream>
#include <vector>
using namespace std;

/*
Problem Statement:
------------------
Given an integer `n`, print all prime numbers from `1` to `n`.

Approach 1: Check Prime Function
--------------------------------
1. A number is **prime** if it has exactly **two divisors**: 1 and itself.
2. We count the number of divisors of `n` by iterating from `1` to `sqrt(n)`.
3. If `n % i == 0`, then both `i` and `n/i` are divisors.
4. If the total count of divisors is exactly **2**, return `true` (prime), otherwise `false`.
5. **Time Complexity:** O(√n) per number.
*/

bool checkPrime(int n) // O(sqrt(n))
{
    int count = 0;

    for (int i = 1; i * i <= n; i++) // Iterate up to sqrt(n)
    {
        if (n % i == 0) // If `i` is a divisor
        {
            count++; // Count `i` as a divisor

            if (n / i != i) // If `n / i` is different, count it separately
            {
                count++;
            }
        }
    }

    return count == 2; // Prime numbers have exactly 2 divisors (1 and itself)
}

/*
Approach 2: Naive Solution (Iterate through all numbers)
--------------------------------------------------------
1. Iterate from `1` to `n`, calling `checkPrime(i)`.
2. Print numbers that are prime.
3. **Time Complexity:** O(n√n) (since `checkPrime(i)` runs in O(√n)).
*/

void printPrimeNumberNaive(int n) // O(n√n)
{
    for (int i = 1; i <= n; i++)
    {
        if (checkPrime(i))
        {
            cout << i << " ";
        }
    }
}

/*
Approach 3: Sieve of Eratosthenes (Efficient)
---------------------------------------------
1. Create a boolean array `isPrime[]` and initialize all values as `true`.
2. Iterate from `2` to `n`, marking multiples as `false`.
3. Numbers left as `true` in `isPrime[]` are prime.
4. **Time Complexity:** O(n log log n) (very efficient).
5. **Space Complexity:** O(n).
*/

void printPrimeNumberEfficient(int n) // O(n log log n)
{
    vector<int> isPrime(n + 1, true); // Boolean array for primes

    for (int i = 2; i <= n; i++) // Iterate from 2 to n
    {
        if (isPrime[i]) // If `i` is prime
        {
            for (int j = 2 * i; j <= n; j = j + i) // Mark multiples as non-prime
            {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) // Print prime numbers
    {
        if (isPrime[i])
        {
            cout << i << " ";
        }
    }
}

/*
Optimized Sieve: Start Multiples from i*i
-----------------------------------------
1. Instead of marking multiples from `2*i`, we start from `i*i`.
2. Reduces unnecessary checks.
3. **Time Complexity:** O(n log log n).
*/

void printPrimeNumberOptimized(int n) // O(n log log n)
{
    vector<int> isPrime(n + 1, true);

    for (int i = 2; i * i <= n; i++) // Iterate up to sqrt(n)
    {
        if (isPrime[i]) // If `i` is prime
        {
            for (int j = i * i; j <= n; j = j + i) // Mark multiples of `i`
            {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) // Print prime numbers
    {
        if (isPrime[i])
        {
            cout << i << " ";
        }
    }
}

/*
Optimized Sieve with Immediate Printing
----------------------------------------
1. Prints prime numbers **as soon as they're found** instead of storing them.
2. Saves space but follows the same logic as the optimized sieve.
*/

void printPrimeNumberOptimizedSoter(int n) // O(n log log n)
{
    vector<int> isPrime(n + 1, true);

    for (int i = 2; i <= n; i++) // Iterate from 2 to n
    {
        if (isPrime[i]) // If `i` is prime
        {
            cout << i << " ";                      // Print `i` immediately
            for (int j = i * i; j <= n; j = j + i) // Mark multiples of `i`
            {
                isPrime[j] = false;
            }
        }
    }
}

// Driver Code
int main()
{
    int n = 23;
    cout << "Prime numbers up to " << n << ":\n";
    printPrimeNumberOptimizedSoter(n);
    return 0;
}
