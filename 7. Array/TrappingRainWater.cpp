#include <iostream>
#include <vector>
using namespace std;

/*
Problem: Trapping Rainwater Problem
- Given an array representing the height of bars, compute how much water can be trapped between these bars after it rains.
- Each element in the array represents the height of a bar.
- Example: For the array {3, 0, 1, 2, 5}, the output should be 6 (water trapped is 3 units between bars 0 and 1, 1 unit between bars 2 and 3, and 2 units between bars 3 and 4).

Approach: We calculate the amount of water trapped over each bar by considering:
- The tallest bar to the left (`lmax`).
- The tallest bar to the right (`rmax`).
- Water trapped at a bar = `min(lmax, rmax) - height of the bar`.
*/

// Naive Approach: For each bar, calculate lmax and rmax separately
// Time Complexity: O(n^2) (nested loops to compute lmax and rmax)
// Space Complexity: O(1) (no extra space used)
int rappingRainWaterNaive(vector<int> &arr)
{
    int res = 0;        // Variable to store the total trapped water
    int n = arr.size(); // Size of the array

    // Loop through each bar (excluding the first and last bars since they can't trap water)
    for (int i = 1; i < n - 1; i++)
    {
        // Calculate lmax (maximum height to the left of the current bar)
        int lmax = arr[i];
        for (int j = 0; j < i; j++)
        {
            lmax = max(lmax, arr[j]);
        }

        // Calculate rmax (maximum height to the right of the current bar)
        int rmax = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            rmax = max(rmax, arr[j]);
        }

        // Calculate water trapped at the current bar
        res += min(lmax, rmax) - arr[i];
    }

    return res; // Return the total trapped water
}

// Efficient Approach: Precompute lmax and rmax arrays
// Time Complexity: O(n) (single traversal of the array and precomputed arrays)
// Space Complexity: O(n) (extra space for lmax and rmax arrays)
int rappingRainWaterEfficient(vector<int> &arr)
{
    int res = 0;        // Variable to store the total trapped water
    int n = arr.size(); // Size of the array

    // Create lmax array to store the maximum height to the left of each bar
    vector<int> lmax(n);
    lmax[0] = arr[0]; // First bar has no bar to its left
    for (int i = 1; i < n; i++)
    {
        lmax[i] = max(lmax[i - 1], arr[i]); // Maximum of current bar or previous lmax
    }

    // Create rmax array to store the maximum height to the right of each bar
    vector<int> rmax(n);
    rmax[n - 1] = arr[n - 1]; // Last bar has no bar to its right
    for (int i = n - 2; i >= 0; i--)
    {
        rmax[i] = max(rmax[i + 1], arr[i]); // Maximum of current bar or next rmax
    }

    // Calculate the water trapped at each bar
    for (int i = 1; i < n - 1; i++)
    {
        res += (min(rmax[i], lmax[i]) - arr[i]); // Water trapped = min(lmax, rmax) - height of the bar
    }

    return res; // Return the total trapped water
}

int main()
{
    // Example array representing bar heights
    vector<int> arr{3, 0, 1, 2, 5};

    // Calculate trapped water using the naive approach
    cout << "Naive Solution: " << rappingRainWaterNaive(arr) << endl;

    // Calculate trapped water using the efficient approach
    cout << "Efficient Solution: " << rappingRainWaterEfficient(arr) << endl;

    return 0;
}
