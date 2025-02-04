#include <iostream>
#include <vector>

using namespace std;

/*
Problem Statement:
------------------
Given a **sorted** array of integers `arr` and an integer `target`, return the **1-based indices**
of the two numbers that add up to `target`. Assume there is exactly one solution.

Approach 1: Naive Solution (Brute Force)
----------------------------------------
1. Use two nested loops to check all possible pairs.
2. If `arr[i] + arr[j] == target`, return `{i, j}`.
3. **Time Complexity:** O(n²) (quadratic due to nested loops).
4. **Space Complexity:** O(1) (no extra space used).
*/

vector<int> twoSumIINaive(vector<int> &arr, int target)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                return {i + 1, j + 1}; // Return 1-based indices
            }
        }
    }
    return {-1, -1}; // Should never reach here (guaranteed solution exists)
}

/*
Approach 2: Two-Pointer Technique (Efficient)
---------------------------------------------
1. Since the array is **sorted**, we use two pointers:
   - `l` starts from the **leftmost** element.
   - `r` starts from the **rightmost** element.
2. Repeat until `l < r`:
   - If `arr[l] + arr[r] > target`, decrement `r` (move right pointer left).
   - If `arr[l] + arr[r] < target`, increment `l` (move left pointer right).
   - If they sum up to `target`, return `{l + 1, r + 1}`.
3. **Time Complexity:** O(n) (linear, as we traverse the array once).
4. **Space Complexity:** O(1) (no extra space used).
*/

vector<int> twoSumII(vector<int> &arr, int target)
{
    int l = 0, r = arr.size() - 1; // Two pointers: left and right

    while (l < r)
    {
        int sum = arr[l] + arr[r]; // Compute sum of elements at left and right pointers

        if (sum > target)
        {
            r--; // Decrease right pointer to reduce sum
        }
        else if (sum < target)
        {
            l++; // Increase left pointer to increase sum
        }
        else
        {
            return {l + 1, r + 1}; // Return 1-based indices
        }
    }

    return {-1, -1}; // Should never execute (guaranteed solution exists)
}

int main()
{
    vector<int> arr{2, 7, 11, 15}; // Sorted input array
    int target = 9;                // Target sum
    vector<int> result = twoSumII(arr, target);

    cout << "Indices: " << result[0] << " " << result[1] << endl;

    return 0;
}
