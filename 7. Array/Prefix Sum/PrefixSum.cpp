#include <iostream>
#include <vector>
using namespace std;

/*
Problem Statement:
------------------
Given an array `arr`, compute the **prefix sum** array where:
- `prefixSum[i]` represents the sum of all elements from `arr[0]` to `arr[i]`.

Approach (Prefix Sum Calculation):
----------------------------------
1. Create a new array `prefixSum` where:
   - `prefixSum[0] = arr[0]` (first element remains the same).
   - `prefixSum[i] = arr[i] + prefixSum[i-1]` for all `i > 0`.
2. This allows us to quickly compute cumulative sums of subarrays in **O(1)** time.
3. **Time Complexity:** O(n), as we traverse the array once.
4. **Space Complexity:** O(n), as we store the prefix sums in a new array.
*/

vector<int> PrefixSum(vector<int> &arr)
{
    vector<int> prefixSum; // Resultant prefix sum array
    int n = arr.size();

    // First element remains the same
    prefixSum.push_back(arr[0]);

    // Compute prefix sum for the rest of the elements
    for (int i = 1; i < n; i++)
    {
        prefixSum.push_back(arr[i] + prefixSum[i - 1]);
    }

    return prefixSum;
}

int main()
{
    vector<int> arr{2, 8, 3, 9, 6, 5, 4}; // Input array
    vector<int> result = PrefixSum(arr);  // Compute prefix sum

    // Print the prefix sum array
    for (int x : result)
    {
        cout << x << " ";
    }

    return 0;
}
