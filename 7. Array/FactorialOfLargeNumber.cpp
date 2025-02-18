#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
Problem Statement:
------------------
Given an integer `n`, compute `n!` (n factorial), which is the product of all numbers from `1` to `n`.
Since factorials grow **very large**, we need to store the result in an array (vector) instead of an integer.

Approach:
---------
1. **Use an array to store the digits of the result** (since `n!` can have hundreds of digits).
2. Start with `arr[0] = 1`, representing `1! = 1`.
3. Iterate from `2` to `n` and multiply each number with the result stored in `arr[]`:
   - Multiply each digit in `arr[]` by `i` (current number).
   - Carry over extra digits when multiplication results in values >= 10.
4. **Reverse the result** at the end since multiplication is stored in reverse order.

Key Observations:
-----------------
- Instead of using `vector<int> arr(1000, 0)`, we can use `vector<int>` dynamically to optimize space.
- **Time Complexity:** `O(n * d)`, where `d` is the number of digits in `n!`. Efficient for large `n`.
- **Space Complexity:** `O(d)`, storing digits in the vector.
*/

vector<int> factorial(int n)
{
    vector<int> arr(1000, 0); // Large array to store digits (worst case for large n)
    arr[0] = 1;               // Factorial of 1 is 1
    int size = 1;             // Number of digits in result (starts with 1 for '1!')

    for (int i = 2; i <= n; i++)
    {
        int carry = 0;

        // Multiply each digit of the stored number by 'i'
        for (int j = 0; j < size; j++)
        {
            int mul = arr[j] * i + carry;
            arr[j] = mul % 10; // Store last digit
            carry = mul / 10;  // Carry forward remaining digits
        }

        // Store carry digits in the array
        while (carry)
        {
            arr[size] = carry % 10; // Store last digit of carry
            size++;                 // Increase size of result
            carry /= 10;            // Remove last digit of carry
        }
    }

    // Store result in correct order (reverse of stored array)
    vector<int> res;
    for (int i = size - 1; i >= 0; i--)
    {
        res.push_back(arr[i]);
    }

    return res;
}

// Optimizations &Benefits
// ✔ Dynamic vector allocation – No wasted space, as vector<int> grows only when needed.
// ✔ Efficient multiplication – Uses carry handling and reverse order storage to handle large numbers.
// ✔ More readable &maintainable – No need to pre - allocate a fixed size array.

vector<int> factorialOptimized(int n)
{
    vector<int> arr;  // Dynamically allocated vector
    arr.push_back(1); // Start with 1! = 1
    int size = 1;     // Current number of digits in the result

    for (int i = 2; i <= n; i++)
    {
        int carry = 0;

        // Multiply each digit of the stored number by 'i'
        for (int j = 0; j < size; j++)
        {
            int mul = arr[j] * i + carry;
            arr[j] = mul % 10; // Store last digit
            carry = mul / 10;  // Carry forward remaining digits
        }

        // Store carry digits in the array
        while (carry)
        {
            arr.push_back(carry % 10); // Push last digit of carry
            carry /= 10;               // Remove last digit from carry
            size++;                    // Increase size of result
        }
    }

    // The result is stored in reverse order, so we reverse before returning
    reverse(arr.begin(), arr.end());
    return arr;
}

int main()
{
    int n = 5; // Example input

    vector<int> result = factorialOptimized(n);
    cout << "Factorial of " << n << " is: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i]; // Print each digit of factorial
    }
    cout << endl;

    return 0;
}
