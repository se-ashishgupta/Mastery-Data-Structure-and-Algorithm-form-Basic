#include <iostream>
#include <vector>
using namespace std;

/*
Problem Statement:
-------------------
Given a sorted array and a target element, find the **first occurrence** of the target.
If the target is not found, return -1.

Example:
--------
Input: arr = [1, 2, 3, 4, 4, 4, 4, 4, 5], target = 4
Output: 3
(First occurrence of 4 is at index 3)
*/

/*
Naive Approach: Linear Search
-----------------------------
1. Traverse the array from left to right.
2. Return the index when the first occurrence of `target` is found.
3. If the element is not found, return -1.

Time Complexity: **O(n)**
Space Complexity: **O(1)**
*/
int firstOccurrenceNaive(vector<int> &arr, int target)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i; // Return the first occurrence index
        }
    }
    return -1; // Target not found
}

/*
Efficient Approach: Binary Search
---------------------------------
1. Apply **Binary Search** to locate the target.
2. If `arr[mid]` equals target:
   - Check if it's the first occurrence (either `mid == 0` or `arr[mid-1] != target`).
   - If not, move **left** (`end = mid - 1`).
3. If `arr[mid]` is greater than `target`, move **left** (`end = mid - 1`).
4. If `arr[mid]` is smaller than `target`, move **right** (`start = mid + 1`).

Time Complexity: **O(log n)**
Space Complexity: **O(1)**
*/
int firstOccurrence(vector<int> &arr, int target)
{
    int n = arr.size();
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2; // Avoid overflow

        if (arr[mid] == target)
        {
            // Check if it's the first occurrence
            if (mid == 0 || arr[mid - 1] != target)
            {
                return mid;
            }
            else
            {
                end = mid - 1; // Search in the left half
            }
        }
        else if (arr[mid] < target)
        {
            start = mid + 1; // Move to right half
        }
        else
        {
            end = mid - 1; // Move to left half
        }
    }
    return -1; // Target not found
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 4, 4, 4, 4, 5};
    int target = 4;
    cout << "First Occurence " << firstOccurrence(arr, target) << endl;

    return 0;
}

/*
Time and Space Complexity Analysis:
-----------------------------------
| Approach      | Time Complexity | Space Complexity |
|--------------|----------------|------------------|
| Naive        | O(n)            | O(1)             |
| Binary Search| O(log n)        | O(1)             |

- The **naive approach** scans the entire array, leading to **O(n)** time complexity.
- The **efficient approach** uses binary search, reducing the complexity to **O(log n)**.
- Both approaches use **O(1) space** since no extra data structures are used.
*/
