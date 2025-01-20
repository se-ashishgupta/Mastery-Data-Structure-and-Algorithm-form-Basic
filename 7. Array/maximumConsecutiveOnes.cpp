#include <iostream>
#include <vector>
using namespace std;

// Problem: Given a binary array (containing only 0s and 1s), find the length of the longest subarray of consecutive 1s.
// Example: For the array {0, 1, 1, 0, 1, 1, 1}, the output should be 3 (longest subarray of consecutive 1s is [1, 1, 1]).
// Constraints: The array only contains 0s and 1s.

// Naive Solution: Nested Loops
// Approach:
// - Start at each index of the array, and for every index, count the number of consecutive 1s.
// - Keep track of the maximum count of consecutive 1s found so far.
// Time Complexity: O(n^2) (For each starting point, traverse the remaining array)
// Space Complexity: O(1) (No extra space used)
int maximumConsecutiveOnesNaive(vector<int> &arr)
{
    int res = 0; // Variable to store the maximum length of consecutive 1s
    int n = arr.size();

    // Traverse the array to check each subarray starting at index i
    for (int i = 0; i < n; i++)
    {
        int curr = 0; // Variable to store the current count of consecutive 1s

        // Count consecutive 1s starting at index i
        for (int j = i; j < n; j++)
        {
            if (arr[j] == 1)
                curr++; // Increment the count if the current element is 1
            else
                break; // Stop counting when a 0 is encountered
        }

        res = max(res, curr); // Update the result if the current count is greater than the previous maximum
    }

    return res; // Return the maximum length of consecutive 1s
}

// Efficient Solution: Single Pass
// Approach:
// - Traverse the array once, maintaining a count of consecutive 1s (`curr`).
// - If a 1 is encountered, increment `curr` and update the result (`res`) if `curr` is greater.
// - If a 0 is encountered, reset `curr` to 0.
// Time Complexity: O(n) (Single traversal of the array)
// Space Complexity: O(1) (No extra space used)
int maximumConsecutiveOnesEfficient(vector<int> &arr)
{
    int res = 0;  // Variable to store the maximum length of consecutive 1s
    int curr = 0; // Variable to store the current count of consecutive 1s
    int n = arr.size();

    // Traverse the array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            curr++;               // Increment the count if the current element is 1
            res = max(res, curr); // Update the result if the current count is greater
        }
        else
        {
            curr = 0; // Reset the count to 0 if the current element is 0
        }
    }

    return res; // Return the maximum length of consecutive 1s
}

int main()
{
    // Example binary array
    vector<int> arr{0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1};

    // Call the naive solution and print the result
    cout << "Naive Solution: " << maximumConsecutiveOnesNaive(arr) << endl;

    // Call the efficient solution and print the result
    cout << "Efficient Solution: " << maximumConsecutiveOnesEfficient(arr) << endl;

    return 0;
}
