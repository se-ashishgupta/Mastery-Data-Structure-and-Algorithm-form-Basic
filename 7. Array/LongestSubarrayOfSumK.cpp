#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
------------------
Given an array and an integer `k`, find the **length of the longest subarray** with sum **equal to k**.

Approach 1: Naive Solution (Brute Force)
----------------------------------------
1. Iterate through all possible subarrays using two nested loops.
2. Compute the sum of the current subarray.
3. If the sum equals `k`, update the maximum length found so far.
4. **Time Complexity:** O(n²) (quadratic due to nested loops).
5. **Space Complexity:** O(1) (no extra space used).
*/

int LongestSubarrayOfSumkNaive(vector<int> &arr, int k)
{
    int n = arr.size();
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = i; j < n; j++)
        {
            sum += arr[j]; // Compute sum of subarray [i...j]

            if (sum == k)
            {
                res = max(res, (j - i) + 1); // Update max length
            }
        }
    }
    return res;
}

/*
Approach 2: Hashing with Prefix Sum (Efficient)
-----------------------------------------------
1. Use a **prefix sum** approach with a hash map (`preSumMap`) to store **first occurrences** of cumulative sums.
2. Traverse the array while maintaining a running sum (`sum`).
3. For each index `i`, check if `(sum - k)` exists in `preSumMap`:
   - If found, it means there exists a **subarray that sums to `k`**.
   - Compute the subarray length and update `res` if it's the longest found.
4. If `sum` has not been seen before, store its index in `preSumMap`.
5. **Time Complexity:** O(n) (single pass over the array).
6. **Space Complexity:** O(n) (to store prefix sums in a map).
*/

int LongestSubarrayOfSumk(vector<int> &arr, int k)
{
    int n = arr.size();

    map<int, int> preSumMap; // Stores {prefix sum -> first occurrence index}
    int sum = 0;             // Running sum
    int res = 0;             // Maximum length of subarray found
    preSumMap[0] = -1;       // To handle cases where subarray starts from index 0

    for (int i = 0; i < n; i++)
    {
        sum += arr[i]; // Update running sum
        cout << "Current Sum at index " << i << ": " << sum << endl;

        int rem = sum - k; // Check if (sum - k) exists in the map

        // If (sum - k) exists, update result with the longest subarray found
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem]; // Calculate subarray length
            res = max(res, len);
        }

        // Store the first occurrence of the current sum
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }

    return res;
}

int main()
{
    vector<int> arr = {10, 5, 2, 7, 1, -10}; // Example array
    int k = 15;                              // Target sum
    cout << "Longest Subarray Length: " << LongestSubarrayOfSumk(arr, k) << endl;

    return 0;
}
