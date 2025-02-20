#include <iostream>
#include <cmath>
using namespace std;

/*
Problem Statement:
-------------------
Given an integer `n`, determine if it is a **prime number**.
A **prime number** is a number greater than 1 that has only two factors: `1` and itself.

Example:
--------
Input: n = 17
Output: true
(17 is prime since it is only divisible by 1 and 17)

Input: n = 18
Output: false
(18 is not prime since it is divisible by 1, 2, 3, 6, 9, and 18)
*/

/*
Naive Approach: Check All Numbers Up to `n`
-------------------------------------------
1. Iterate from `2` to `n-1`.
2. If any number divides `n`, return `false` (not prime).
3. If no number divides `n`, return `true` (prime).

Time Complexity: **O(n)**
Space Complexity: **O(1)**
*/
bool checkPrimeNaive(int a)
{
    if (a <= 1)
        return false;

    for (int i = 2; i < a; i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}

/*
Optimized Approach: Check Up to `sqrt(n)`
-----------------------------------------
1. A number `n` has a factor **greater than sqrt(n)** only if it has a factor **less than sqrt(n)**.
2. Iterate only up to `sqrt(n)`, checking divisibility.
3. If a factor is found, return `false`. Otherwise, return `true`.

Time Complexity: **O(√n)**
Space Complexity: **O(1)**
*/
bool checkPrimeEfficient(int a)
{
    if (a <= 1)
        return false;

    for (int i = 2; i * i <= a; i++) // Equivalent to `i <= sqrt(n)`
    {
        if (a % i == 0)
            return false;
    }
    return true;
}

/*
Alternative Efficient Approach: Counting Factors Up to `sqrt(n)`
----------------------------------------------------------------
1. Instead of stopping on the first factor, count the total number of factors.
2. If `n` has exactly **2 factors** (`1` and `n`), it's prime.

Time Complexity: **O(√n)**
Space Complexity: **O(1)**
*/
bool checkPrimeEfficient1(int a)
{
    int count = 0;

    for (int i = 1; i <= sqrt(a); i++)
    {
        if (a % i == 0)
        {
            count++;

            // If `i` is not the square root of `a`, count both `i` and `a/i`
            if (a / i != i)
            {
                count++;
            }
        }
    }
    return count == 2; // Prime numbers must have exactly 2 factors
}

/*
Most Optimal Approach: Skip Even & Multiples of 3
-------------------------------------------------
1. **Eliminate even numbers** (except 2) and multiples of 3 (except 3).
2. Check divisibility only for numbers in the form of **6k ± 1** (5, 7, 11, 13, ...).
3. This significantly reduces the number of iterations.

Time Complexity: **O(√n)** (Faster than basic `O(√n)`)
Space Complexity: **O(1)**
*/
bool checkPrimeOptimal(int a)
{
    if (a <= 1)
        return false;

    if (a == 2 || a == 3)
        return true;

    if (a % 2 == 0 || a % 3 == 0)
        return false;

    for (int i = 5; i * i <= a; i += 6) // Check 6k ± 1 numbers
    {
        if (a % i == 0 || a % (i + 2) == 0)
            return false;
    }

    return true;
}

int main()
{
    int num = 17;
    cout << "Is " << num << " prime? " << (checkPrimeOptimal(num) ? "Yes" : "No") << endl;
    return 0;
}

/*
Summary Table:
------------------------------------------------------
| Approach                        | Time Complexity | Space Complexity |
|----------------------------------|----------------|------------------|
| Naive (Check all numbers)       | O(n)           | O(1)             |
| Optimized (Check up to sqrt(n)) | O(√n)          | O(1)             |
| Counting Factors                | O(√n)          | O(1)             |
| Most Optimal (6k ± 1 method)    | O(√n) (faster) | O(1)             |
------------------------------------------------------
*/
