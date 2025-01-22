#include <iostream>
#include <vector>
using namespace std;

/*
Problem: Maximum Length Even-Odd Subarray
- You are given an array of integers.
- Find the maximum length of a subarray where elements alternate between even and odd.
- Example: For the array {10, 12, 14, 7, 8}, the maximum length of an alternating even-odd subarray is 3 ({14, 7, 8}).

---

Naive Approach:
1. Use two nested loops:
   - The outer loop selects a starting point.
   - The inner loop checks for alternating even-odd elements from the starting point.
2. Keep track of the maximum alternating subarray length (`res`).
3. Complexity:
   - **Time**: O(n²), as every possible subarray is checked.
   - **Space**: O(1), no extra space is used.
*/

int maximumEvenOddSubarrayNaive(vector<int> &arr)
{
    int n = arr.size(); // Size of the array
    int res = 1;        // Initialize result to 1 (minimum possible subarray length)

    // Outer loop: Start from every index
    for (int i = 0; i < n; i++)
    {
        int count = 1; // Start a new subarray

        // Inner loop: Check alternating even-odd elements
        for (int j = i + 1; j < n; j++)
        {
            if ((arr[j] % 2 == 0 && arr[j - 1] % 2 == 1) || (arr[j] % 2 == 1 && arr[j - 1] % 2 == 0))
            {
                count++; // Increment count if the even-odd pattern is maintained
            }
            else
            {
                break; // Stop if the pattern breaks
            }
        }

        // Update the result if a longer subarray is found
        res = max(res, count);
    }

    return res; // Return the maximum length
}

/*
Efficient Approach:
1. Traverse the array once while maintaining:
   - `count`: The current length of the alternating subarray.
   - `res`: The maximum length encountered so far.
2. At each step:
   - If the even-odd pattern is maintained, increment `count` and update `res`.
   - Otherwise, reset `count` to 1.
3. Complexity:
   - **Time**: O(n), as the array is traversed once.
   - **Space**: O(1), no extra space is used.
*/

int maximumEvenOddSubarray(vector<int> &arr)
{
    int n = arr.size();     // Size of the array
    int res = 1, count = 1; // Initialize result and count to 1

    // Traverse the array
    for (int i = 1; i < n; i++)
    {
        // Check if the even-odd pattern is maintained
        if ((arr[i] % 2 == 0 && arr[i - 1] % 2 == 1) || (arr[i] % 2 == 1 && arr[i - 1] % 2 == 0))
        {
            count++;               // Increment the current length
            res = max(res, count); // Update the result if a longer subarray is found
        }
        else
        {
            count = 1; // Reset the count if the pattern breaks
        }
    }

    return res; // Return the maximum length
}

int main()
{
    // Example array
    vector<int> arr{10, 12, 14, 7, 8};

    // Print the result using the efficient approach
    cout << "Maximum Length of Even-Odd Subarray: " << maximumEvenOddSubarray(arr) << endl;

    return 0;
}
