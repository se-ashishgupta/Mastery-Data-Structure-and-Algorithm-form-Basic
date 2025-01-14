#include <iostream>
#include <vector>
using namespace std;

// Function to check if the array is sorted and rotated
// Time Complexity: O(n) (Linear time due to a single pass through the array)
// Auxiliary Space: O(1) (No extra space used)
bool checkSortedAndRotated(vector<int> &nums)
{
    int i;
    int n = nums.size();

    // Iterate through the array to find the point where the sorting breaks
    for (i = 1; i < n; i++)
    {
        // If the current element is smaller than the previous one, sorting is broken
        if (nums[i] < nums[i - 1])
        {
            break;
        }
    }

    // If no break point is found, the array is already sorted (not rotated)
    if (i == n)
        return true; // Array is sorted but not rotated

    // If the last element is greater than the first, it can't be a rotated sorted array
    if (nums[n - 1] > nums[0])
        return false; // Not sorted and rotated

    // Check if the remaining part of the array is sorted
    for (int j = i + 1; j < n; j++)
    {
        if (nums[j] < nums[j - 1])
        {
            return false; // Sorting breaks, array is not rotated and sorted
        }
    }

    // Check if the first part of the array is sorted (from the break point)
    for (int j = 1; j < i; j++)
    {
        if (nums[j] < nums[j - 1])
        {
            return false; // Sorting breaks, array is not rotated and sorted
        }
    }

    return true; // Array is sorted and rotated properly
}

// Optimized function to check if the array is sorted and rotated
// Time Complexity: O(n) (Single loop to count the break points)
// Auxiliary Space: O(1) (No extra space used)
bool checkSortedAndRotated1(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;

    // Iterate through the array to count the number of break points where sorting fails
    for (int i = 1; i < n; i++)
    {
        if (nums[i] < nums[i - 1])
        {
            count++; // Increment count when sorting breaks
        }
    }

    // Check the transition from the last element to the first element
    if (nums[n - 1] > nums[0])
    {
        count++; // Increment count if the last element is greater than the first
    }

    // The array is sorted and rotated if there's at most one break point
    return count <= 1;
    // If count is greater than 1, it means the array is not sorted, not rotated properly, or rotated more than once
    // The function returns true if count <= 1, meaning there is at most one break in the sorted order, which would make the array sorted and rotated.If count > 1, it means the array is either not sorted, not rotated properly, or rotated more than once, so it returns false.
}

int main()
{
    vector<int> arr = {3, 4, 5, 1, 2};

    // Call the optimized function and print the result
    cout << checkSortedAndRotated1(arr); // Output: 1 (True, because the array is sorted and rotated)

    return 0;
}
