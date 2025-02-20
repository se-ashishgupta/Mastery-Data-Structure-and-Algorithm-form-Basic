#include <iostream>
#include <vector>
using namespace std;

/*
Problem Statement:
------------------
Find the index of the **pivot element** in a rotated sorted array.

Optimized Approach:
-------------------
1. **Check if array is already sorted**:
   - If `arr[start] <= arr[end]`, return `start` (smallest element is at index `0`).
2. **Use Binary Search**:
   - If `arr[mid] > arr[end]`, pivot is in the **right half**.
   - Else, pivot is in the **left half**.
3. **Loop stops when `start == end`**, which gives the pivot index.

Time Complexity: O(log n)  (Binary search reduces search space by half in each step)
Space Complexity: O(1)     (Uses constant extra space)
*/

int RotationPivot(vector<int> &arr)
{
    int n = arr.size();
    int start = 0, end = n - 1;

    // Check if the array is already sorted
    if (arr[start] <= arr[end])
    {
        return start; // The smallest element is at index 0
    }

    // Binary Search to find the pivot index
    while (start < end)
    {
        int mid = start + (end - start) / 2; // Avoids integer overflow

        // If mid element is greater than end, pivot is in the right half
        if (arr[mid] > arr[end])
        {
            start = mid + 1; // Move to right half
        }
        else
        {
            end = mid; // Move to left half
        }
    }

    return start; // Pivot index (index of smallest element)
}

int main()
{
    vector<int> arr = {0, 1, 2, 4, 5};                     // Example of already sorted array
    cout << "Pivot index: " << RotationPivot(arr) << endl; // Expected output: 0
    return 0;
}
