#include <iostream>
#include <vector>
using namespace std;

// Problem: Find the maximum difference (arr[j] - arr[i]) in the array such that j > i.
// Example: For the array {2, 3, 10, 6, 4, 8, 1}, the maximum difference is 10 - 2 = 8.

// Naive Approach 1
// Time Complexity: O(n^2) (Two nested loops)
// Auxiliary Space: O(1) (No extra space used)
int maximumDifferenceNaive(vector<int> &arr)
{
    int maxDiff = 0; // Initialize the maximum difference
    int n = arr.size();

    // Loop through the array to fix the second element
    for (int i = 1; i < n; i++)
    {
        int min = 0;

        // Loop through all elements before i to find the maximum difference
        for (int j = 0; j < i; j++)
        {
            if (arr[i] - arr[j] > min)
            {
                min = arr[i] - arr[j]; // Update the local maximum difference
            }
        }

        maxDiff = max(maxDiff, min); // Update the global maximum difference
    }

    return maxDiff;
}

// Naive Approach 2
// Time Complexity: O(n^2) (Two nested loops)
// Auxiliary Space: O(1) (No extra space used)
int maximumDifferenceNaive1(vector<int> &arr)
{
    int maxDiff = arr[1] - arr[0]; // Initialize the maximum difference
    int n = arr.size();

    // Loop through all pairs of elements (i, j) where j > i
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            maxDiff = max(maxDiff, (arr[j] - arr[i])); // Update the global maximum difference
        }
    }

    return maxDiff;
}

// Efficient Approach
// Time Complexity: O(n) (Single loop through the array)
// Auxiliary Space: O(1) (No extra space used)
int maximumDifferenceEfficient(vector<int> &arr)
{
    int maxDiff = arr[1] - arr[0]; // Initialize the maximum difference
    int n = arr.size();
    int minVal = arr[0]; // Track the minimum value seen so far

    // Traverse the array from the second element
    for (int i = 1; i < n; i++)
    {
        maxDiff = max(maxDiff, arr[i] - minVal); // Update the global maximum difference
        minVal = min(minVal, arr[i]);            // Update the minimum value seen so far
    }

    return maxDiff;
}

int main()
{
    // Example input array
    vector<int> arr{2, 3, 10, 6, 4, 8, 1};

    // Call the efficient function and print the result
    cout << maximumDifferenceEfficient(arr);

    return 0;
}
