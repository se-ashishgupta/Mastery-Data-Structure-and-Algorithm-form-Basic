#include <iostream>
using namespace std;

/*
Problem: Find the **integer** square root of a given number n.

Approach:
1. **Binary Search (O(log n))**
   - Start with `start = 1` and `end = n`.
   - Check if `mid * mid == n`.
   - If `mid * mid < n`, move `start = mid + 1` (store `mid` as a candidate).
   - Otherwise, move `end = mid - 1`.

Edge Cases:
- **n = 0, 1** → Return `n` directly.
- **Large n (10^9+)** → Use `long long` to avoid integer overflow.
*/

int SquareRoot(int n)
{
    if (n == 0 || n == 1)
        return n; // Edge case handling

    int start = 1, end = n, res = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2; // Avoid overflow
        long long sq = (long long)mid * mid; // Use long long for safety

        if (sq == n)
        {
            return mid; // Perfect square found
        }
        else if (sq < n)
        {
            res = mid; // Store possible answer
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return res; // Closest integer square root
}

int main()
{
    int n = 24;
    cout << "Integer Square Root of " << n << " is: " << SquareRoot(n) << endl;
    return 0;
}
