#include <iostream>
#include <vector>
using namespace std;

/*
Problem Statement:
------------------
Given an array of integers and an integer `k`, find the maximum sum of `k` consecutive
elements in the array.

Naive Approach (Brute Force):
-----------------------------
1. Iterate through all possible subarrays of size `k` using two nested loops.
2. Compute the sum of each subarray and update the maximum sum found.
3. **Time Complexity:** O(n*k), as for each starting index, we iterate `k` elements.
4. **Space Complexity:** O(1), as no extra space is used.
*/

int maxSumKConsNumberNaive(vector<int> &arr, int k)
{
    int n = arr.size();
    int res = 0;

    for (int i = 0; i <= n - k; i++) // Iterate through possible subarrays
    {
        int sum = 0;
        for (int j = 0; j < k; j++) // Compute sum of current subarray
        {
            sum += arr[j + i];
        }
        res = max(res, sum); // Update max sum found so far
    }
    return res;
}

/*
Efficient Approach: Sliding Window Technique
--------------------------------------------
1. Compute the sum of the first `k` elements (initial window).
2. Slide the window by removing the first element of the previous window and adding the next element.
3. Maintain and update the maximum sum found.
4. **Time Complexity:** O(n), as each element is added and removed once.
5. **Space Complexity:** O(1), since only a few variables are used.
*/

int maxSumKConsNumber(vector<int> &arr, int k)
{
    int n = arr.size();
    int sum = 0;

    // Compute sum of first 'k' elements (initial window)
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }

    int res = sum; // Store the initial sum as max

    // Slide the window through the array
    for (int i = k; i < n; i++)
    {
        sum += arr[i] - arr[i - k]; // Remove leftmost element and add new element
        res = max(res, sum);        // Update max sum found
    }

    return res;
}

int main()
{
    vector<int> arr{1, 8, 30, -5, 20, 7};
    int k = 3;
    cout << maxSumKConsNumber(arr, k);
    return 0;
}
