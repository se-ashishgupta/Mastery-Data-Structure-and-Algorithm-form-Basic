#include <iostream>
#include <vector>

using namespace std;

/*
Problem:
Given a sorted array, find the first occurrence of a target element.
Then compute the total occurrences using: `arr.size() - firstOccurrenceIndex`.

Approach:
1. **Naive O(n) approach** → Linear search.
2. **Efficient O(log n) approach** → Binary Search.

Time Complexity:
- Naive: O(n) (Linear scan)
- Optimized: O(log n) (Binary search)

Space Complexity: O(1) (No extra space used)
*/

// Naive approach: Linear search (O(n))
int firstOccurrenceNaive(vector<int> &arr, int target)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1; // Target not found
}

// Optimized approach: Binary Search (O(log n))
int firstOccurrence(vector<int> &arr, int target)
{
    int n = arr.size();
    int start = 0, end = n - 1;
    int firstIndex = -1; // Default to -1 (not found)

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
        {
            firstIndex = mid; // Store the index
            end = mid - 1;    // Move left to find first occurrence
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return firstIndex;
}

int main()
{
    vector<int> arr = {0, 0, 0, 1, 1, 1, 1, 1, 1, 1};
    int target = 1;

    int first = firstOccurrence(arr, target);

    if (first == -1)
    {
        cout << "Target not found in the array." << endl;
    }
    else
    {
        cout << "Total occurrences of " << target << " = " << arr.size() - first << endl;
    }

    return 0;
}
