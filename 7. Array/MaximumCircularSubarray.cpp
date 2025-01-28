#include <iostream>
#include <vector>

using namespace std;

/*
Problem: Maximum Circular Subarray Sum
- Find the maximum sum of a subarray in a circular array.
- A circular array means that elements wrap around (e.g., last element connects to the first).
- Example: For {8, -4, 3, -5, 4}, the maximum circular subarray sum is 12 ({4, 8}).

---

### Naive Approach:
1. Use two nested loops:
   - Outer loop selects the starting point.
   - Inner loop iterates over all elements while considering the circular nature of the array.
2. Complexity:
   - **Time**: O(n²), as every possible subarray is checked.
   - **Space**: O(1), no extra space is used.
*/

int MaximumCircularSubarrayNaive(vector<int> &arr)
{
    int n = arr.size(); // Size of the array
    int res = arr[0];   // Initialize result with the first element

    // Outer loop: Start from every index
    for (int i = 0; i < n; i++)
    {
        int sum = 0; // Reset sum for the new starting point

        // Inner loop: Traverse the array in a circular manner
        for (int j = 0; j < n; j++)
        {
            int circIndex = (i + j) % n; // Circular indexing
            sum += arr[circIndex];       // Add current element
            res = max(res, sum);         // Update result if the sum is larger
        }
    }

    return res; // Return the maximum circular subarray sum
}

/*
Efficient Approach:
1. Split the problem into two cases:
   - **Normal Maximum Subarray Sum** (using Kadane's Algorithm).
   - **Circular Maximum Subarray Sum**.
2. Combine results to get the maximum sum.

---

**Case 1: Normal Maximum Subarray Sum**
- This is the standard Kadane's Algorithm to find the maximum sum of a subarray.
- Complexity:
   - **Time**: O(n)
   - **Space**: O(1)
*/

int MaximumCircularSubarrayNoraml(vector<int> &arr)
{
    int n = arr.size();     // Size of the array
    int res = arr[0];       // Initialize result with the first element
    int maxEnding = arr[0]; // Maximum sum ending at the current position

    // Traverse the array to calculate maximum subarray sum
    for (int i = 1; i < n; i++)
    {
        maxEnding = max(maxEnding + arr[i], arr[i]); // Extend the current subarray or start a new one
        res = max(res, maxEnding);                   // Update result
    }

    return res; // Return the normal maximum subarray sum
}

/*
**Case 2: Circular Maximum Subarray Sum**
1. To handle circular nature:
   - Compute the total sum of the array.
   - Invert the array elements (make all elements negative).
   - Use Kadane's Algorithm to find the maximum sum subarray of the inverted array.
   - Subtract this sum from the total sum to get the circular maximum.
   -  The maximum sum of a circular subarray can be defined as the total sum of the array minus the sum of a subarray in the middle. So, to maximize the circular subarray sum, we need to minimize the subarray sum.
2. Complexity:
   - **Time**: O(n)
   - **Space**: O(1)
*/

int MaximumCircularSubarrayCircular(vector<int> &arr)
{
    int n = arr.size(); // Size of the array
    int sum = 0;        // Total sum of the array

    // Calculate the total sum and invert the array
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];    // Add the current element to the total sum
        arr[i] = -arr[i]; // Invert the element (make it negative)
    }

    // Calculate the maximum sum subarray of the inverted array
    int invertedMax = MaximumCircularSubarrayNoraml(arr);

    // Return the circular maximum sum as total sum - (-max of inverted array)
    return sum + invertedMax;
}

/*
**Final Efficient Approach: Combine the Two Cases**
1. Use both:
   - Normal maximum subarray sum.
   - Circular maximum subarray sum.
2. If the normal maximum is negative (all elements are negative), return it directly.
3. Otherwise, return the maximum of the two cases.
*/

int MaximumCircularSubarrayEfficient(vector<int> &arr)
{
    // Calculate the normal maximum subarray sum
    int maxNormal = MaximumCircularSubarrayNoraml(arr);

    // If all elements are negative, return the normal maximum
    if (maxNormal < 0)
    {
        return maxNormal;
    }

    // Calculate the circular maximum subarray sum
    int maxCircular = MaximumCircularSubarrayCircular(arr);

    // Return the maximum of the two cases
    return max(maxNormal, maxCircular);
}

// Function to calculate the maximum circular subarray sum
int circularSubarraySum(vector<int> &arr)
{
    int totalSum = 0;    // Total sum of the array
    int currMaxSum = 0;  // Running sum for maximum subarray (Kadane's)
    int currMinSum = 0;  // Running sum for minimum subarray (Kadane's)
    int maxSum = arr[0]; // Initialize max subarray sum with first element
    int minSum = arr[0]; // Initialize min subarray sum with first element

    // Iterate through the array
    for (int i = 0; i < arr.size(); i++)
    {
        // Kadane's algorithm to find the maximum sum subarray
        currMaxSum = max(currMaxSum + arr[i], arr[i]);
        maxSum = max(maxSum, currMaxSum); // Update the global maximum sum

        // Kadane's algorithm to find the minimum sum subarray
        currMinSum = min(currMinSum + arr[i], arr[i]);
        minSum = min(minSum, currMinSum); // Update the global minimum sum

        // Calculate the total sum of the array
        totalSum = totalSum + arr[i];
    }

    // Calculate the normal (non-circular) maximum sum
    int normalSum = maxSum;

    // Calculate the circular maximum sum by subtracting the minimum subarray sum from the total sum
    int circularSum = totalSum - minSum;

    // Handle the edge case where all elements are negative:
    // In this case, `minSum == totalSum`, and we should return `normalSum` directly
    if (minSum == totalSum)
        return normalSum;

    // Return the maximum of normal maximum sum and circular maximum sum
    return max(normalSum, circularSum);
}

int main()
{
    // Example array
    vector<int> arr{8, -4, 3, -5, 4};

    // Calculate the maximum circular subarray sum
    int maxSum = circularSubarraySum(arr);

    // Print the result
    cout << "Maximum sum of a circular subarray is " << maxSum << endl;

    return 0;
}
