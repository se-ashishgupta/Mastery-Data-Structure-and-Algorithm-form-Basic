#include <iostream>
#include <vector>

using namespace std;

/*
 * PROBLEM STATEMENT:
 * -------------------
 * Given a **sorted array** and a **target element**, find the **last occurrence** of the target in the array.
 * If the target is not present, return `-1`.
 *
 * Example:
 * ---------
 * Input:
 *    arr = {1, 2, 3, 4, 4, 4, 4, 4, 5};
 *    target = 4;
 * Output:
 *    Last Occurrence (Binary Search): 7
 *    Last Occurrence (Naive): 7
 *
 * Explanation:
 *  - The element `4` appears at indices {3, 4, 5, 6, 7}.
 *  - The **last occurrence** of `4` is at index `7`.
 */

/*
 * NAIVE APPROACH: Linear Search (O(n))
 * --------------------------------------
 * 1. Start from the last index and move backward.
 * 2. If `arr[i] == target`, return `i`.
 * 3. If not found, return -1.
 */
int LastOccurrenceNaive(vector<int> &arr, int target)
{
    int n = arr.size();

    for (int i = n - 1; i >= 0; i--) // Start from the last index
    {
        if (arr[i] == target)
        {
            return i; // Return the last occurrence index
        }
    }
    return -1; // Target not found
}

/*
 * OPTIMIZED APPROACH: Binary Search (O(log n))
 * ---------------------------------------------
 * 1. Perform a **modified binary search** to locate the last occurrence.
 * 2. If `arr[mid] == target`:
 *    - If `mid == n - 1` (last index) or `arr[mid + 1] != target`, return `mid`.
 *    - Else, search in the **right half** (`start = mid + 1`).
 * 3. If `arr[mid] < target`, search right (`start = mid + 1`).
 * 4. If `arr[mid] > target`, search left (`end = mid - 1`).
 */
int LastOccurrence(vector<int> &arr, int target)
{
    int n = arr.size();
    int start = 0, end = n - 1;
    int result = -1; // Store the last occurrence index

    while (start <= end)
    {
        int mid = start + (end - start) / 2; // Avoid overflow

        if (arr[mid] == target)
        {
            result = mid;    // Store current occurrence
            start = mid + 1; // Search in the right half for later occurrences
        }
        else if (arr[mid] < target)
        {
            start = mid + 1; // Search right
        }
        else
        {
            end = mid - 1; // Search left
        }
    }

    return result; // Return the last occurrence index
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 4, 4, 4, 4, 5}; // Sorted array
    int target = 4;

    // Using optimized binary search
    cout << "Last Occurrence (Binary Search): " << LastOccurrence(arr, target) << endl;

    // Using naive approach
    cout << "Last Occurrence (Naive): " << LastOccurrenceNaive(arr, target) << endl;

    return 0;
}

/*
 * COMPLEXITY ANALYSIS:
 * ---------------------
 * | Approach          | Time Complexity | Space Complexity |
 * |------------------|---------------|----------------|
 * | **Naive**        | O(n)          | O(1)           |
 * | **Binary Search** | O(log n)      | O(1)           |
 *
 * ✔ **Binary search is significantly faster for large sorted arrays!**
 */
