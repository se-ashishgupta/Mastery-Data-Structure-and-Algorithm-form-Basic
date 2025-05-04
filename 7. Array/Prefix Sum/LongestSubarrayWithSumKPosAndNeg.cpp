#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
Problem Statement:
-------------------
Given an array of integers `arr` and an integer `k`,
find the length of the **longest subarray** whose sum equals `k`.

Example 1:
----------
Input: arr = [10, 5, 2, 7, 1, -10], k = 15
Output: 4
Explanation: The subarray [5, 2, 7, 1] sums to 15.

Example 2:
----------
Input: arr = [1, 2, 3, 4, 5], k = 9
Output: 3
Explanation: Subarray [2, 3, 4] sums to 9.

*/

/*
Naive Approach:
----------------
1. Use two nested loops to calculate the sum of all subarrays.
2. If sum equals k, update the maximum length.
Time Complexity: O(N^2)
Space Complexity: O(1)
*/
int longestSubarrayWithSumKNaive(vector<int> &arr, int k)
{
    int res = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                res = max(res, j - i + 1);
            }
        }
    }

    return res;
}

/*
Optimized Approach: Using Prefix Sum + HashMap
----------------------------------------------
1. Maintain a running sum (prefix sum).
2. Store first occurrence of each prefix sum in a map.
3. If current prefix sum - k exists in map, calculate the subarray length.
4. If prefix sum equals k, the subarray is from index 0 to i.

Time Complexity: O(N)
Space Complexity: O(N)
*/
int longestSubarrayWithSumKEfficient(vector<int> &arr, int k)
{
    int n = arr.size();
    int res = 0, sum = 0;
    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        // If full prefix sum from 0 to i equals k
        if (sum == k)
        {
            res = max(res, i + 1);
        }

        // If there exists a prefix sum such that sum - k = previous sum
        if (mp.find(sum - k) != mp.end())
        {
            res = max(res, i - mp[sum - k]);
        }

        // Store only the first occurrence of this prefix sum
        if (mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
    }

    return res;
}

int main()
{
    vector<int> arr = {10, 5, 2, 7, 1, -10};
    int k = 15;

    cout << "Longest Subarray With Sum K is of Length: " << longestSubarrayWithSumKEfficient(arr, k) << endl;

    return 0;
}

/*
Summary Table:
-----------------------------------------------------
| Approach                 | Time Complexity | Space Complexity |
|--------------------------|-----------------|------------------|
| Naive (Brute Force)      | O(N^2)          | O(1)             |
| Optimized (Prefix + Map) | O(N)            | O(N)             |
-----------------------------------------------------
*/
