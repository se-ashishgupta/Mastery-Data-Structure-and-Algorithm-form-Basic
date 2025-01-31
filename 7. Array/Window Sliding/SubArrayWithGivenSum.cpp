#include <iostream>
#include <vector>
using namespace std;

/*
Problem Statement:
------------------
Given an array and a target sum, check if there exists a **contiguous subarray** whose sum is equal to the given sum.

Naive Approach (Brute Force):
-----------------------------
1. Use two nested loops to check all possible subarrays.
2. Compute the sum of each subarray.
3. If any subarray sum matches the given sum, return `true`.
4. **Time Complexity:** O(n²), as we check every possible subarray.
5. **Space Complexity:** O(1), as no extra space is used.
*/

bool subarrayWithGivenSumNaive(vector<int> &arr, int sum)
{
    int n = arr.size();

    for (int i = 0; i < n; i++) // Starting point of subarray
    {
        int current_sum = 0;

        for (int j = i; j < n; j++) // Ending point of subarray
        {
            current_sum += arr[j]; // Accumulate sum
            if (current_sum == sum)
            {
                return true; // Found subarray with given sum
            }
        }
    }

    return false; // No subarray found
}

/*
Efficient Approach: Sliding Window (Two Pointer)
------------------------------------------------
1. Maintain a **window sum** starting from index `s = 0`.
2. Expand the window by adding `arr[i]` to `current_sum`.
3. If `current_sum` exceeds the target sum, **shrink the window** from the left.
4. Stop when `current_sum` matches the target sum.
5. **Time Complexity:** O(n), as each element is processed only once.
6. **Space Complexity:** O(1), as only a few variables are used.
*/

bool subarrayWithGivenSum(vector<int> &arr, int sum)
{
    int n = arr.size();
    int current_sum = 0; // Stores the sum of current window
    int s = 0;           // Left boundary of the window

    for (int i = 0; i < n; i++)
    {
        // Expand window
        current_sum += arr[i];

        // Shrink window from the left while sum exceeds target
        while (current_sum > sum && s < i)
        {
            current_sum -= arr[s];
            s++;
        }

        // Check if current sum matches the target
        if (current_sum == sum)
        {
            return true;
        }
    }

    return false; // No subarray found
}

int main()
{
    vector<int> arr{1, 4, 20, 3, 10, 5};
    int sum = 33;
    cout << (subarrayWithGivenSum(arr, sum) ? "Yes" : "No");
    return 0;
}
