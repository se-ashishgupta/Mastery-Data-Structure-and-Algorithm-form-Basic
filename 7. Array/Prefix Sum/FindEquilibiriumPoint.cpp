#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Problem Statement:
------------------
An **equilibrium point** in an array is an index `i` such that the sum of elements
to the **left of `i`** is equal to the sum of elements to the **right of `i`**.

Naive Approach (Brute Force):
-----------------------------
1. Iterate through every index `i` and calculate:
   - `leftSum`: Sum of elements from `0` to `i-1`
   - `rightSum`: Sum of elements from `i+1` to `n-1`
2. If `leftSum == rightSum`, return `true` (equilibrium exists).
3. **Time Complexity:** O(n²), since we compute sum for every index.
4. **Space Complexity:** O(1), as we only use a few variables.
*/

bool hasEquilibiriumPointNaive(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++) // Checking equilibrium at each index
    {
        int leftSum = 0, rightSum = 0;

        // Compute sum of elements on the left of index i
        for (int j = 0; j < i; j++)
        {
            leftSum += arr[j];
        }
        // Compute sum of elements on the right of index i
        for (int j = i + 1; j < n; j++)
        {
            rightSum += arr[j];
        }

        // If left sum and right sum are equal, equilibrium found
        if (leftSum == rightSum)
            return true;
    }
    return false;
}

/*
Efficient Approach (Single Pass Using Total Sum Trick):
--------------------------------------------------------
1. Compute the **total sum** of the array.
2. Traverse through the array while maintaining `leftSum`:
   - At index `i`, if `leftSum == (totalSum - arr[i])`, return `true`.
   - Update `leftSum` and reduce `totalSum` in each step.
3. **Time Complexity:** O(n), as we traverse the array once.
4. **Space Complexity:** O(1), no extra space used.
*/

bool hasEquilibiriumPointEfficient(vector<int> &arr)
{
    int n = arr.size();
    int sum = 0; // Stores total sum of the array
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int leftSum = 0; // Tracks left-side sum
    for (int i = 0; i < n; i++)
    {
        // If left sum is equal to right sum (computed using total sum)
        if (leftSum == sum - arr[i])
        {
            return true;
        }

        // Update leftSum and decrease sum by arr[i]
        leftSum += arr[i];
        sum -= arr[i];
    }

    return false;
}

/*
Approach Using Prefix Sum:
--------------------------
1. Compute **prefix sum** array where `prefixSum[i]` is sum of elements from `0` to `i`.
2. Compute **suffix sum** array where `suffixSum[i]` is sum of elements from `i` to `n-1`.
3. If for any `i`: `prefixSum[i] - suffixSum[i] == 0`, return `true`.
4. **Time Complexity:** O(n), but uses extra space.
5. **Space Complexity:** O(n), as two extra arrays are used.
*/

bool hasEquilibiriumPointUsingPrefixSum(vector<int> &arr)
{
    int n = arr.size();

    // Compute prefix sum
    vector<int> prefixSum(n);
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    // Compute suffix sum
    vector<int> suffixSum(n);
    suffixSum[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffixSum[i] = suffixSum[i + 1] + arr[i];
    }

    // Check if any index satisfies prefixSum - suffixSum = 0
    for (int i = 0; i < n; i++)
    {
        if (prefixSum[i] - suffixSum[i] == 0)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> arr{3, 4, 8, -9, 20, 6};
    cout << (hasEquilibiriumPointEfficient(arr) ? "Yes" : "No");
    return 0;
}

// Complexity Analysis:
// Approach	                    Time Complexity	Space Complexity	Notes
// Naive (Brute Force)	        O(n²)	        O(1)	            Checks all indices
// Efficient (Total Sum Trick)	O(n)	        O(1)	            Best approach
// Prefix Sum Method	        O(n)	        O(n)	            Uses extra space
