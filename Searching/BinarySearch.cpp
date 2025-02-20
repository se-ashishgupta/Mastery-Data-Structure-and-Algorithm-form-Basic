#include <iostream>
#include <vector>
using namespace std;

/*
Binary Search (Iterative Approach)
----------------------------------
Time Complexity: O(log n)  -> Since the search space reduces by half each time.
Space Complexity: O(1)     -> No extra memory is used.

Steps:
1. Start with two pointers `l` (left) and `r` (right).
2. While `l` is less than or equal to `r`:
   - Compute `mid = l + (r - l) / 2`.
   - If `arr[mid] == target`, return `mid` (found).
   - If `arr[mid] > target`, search the **left half** (`r = mid - 1`).
   - Else, search the **right half** (`l = mid + 1`).
3. If not found, return `-1`.
*/
int binarySearch(vector<int> &arr, int target)
{
    int n = arr.size();
    int l = 0, r = n - 1;

    while (l <= r) // Fix: Should be "<=" to include the last element
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == target)
        {
            return mid; // Found target, return index
        }
        else if (arr[mid] > target)
        {
            r = mid - 1; // Search left half
        }
        else
        {
            l = mid + 1; // Search right half
        }
    }

    return -1; // Target not found
}

/*
Binary Search (Recursive Approach)
----------------------------------
Time Complexity: O(log n)  -> Due to the halving of search space.
Space Complexity: O(log n) -> Due to recursive function calls (stack space).

Steps:
1. Compute `mid = l + (r - l) / 2`.
2. If `arr[mid] == target`, return `mid`.
3. If `arr[mid] > target`, recursively search **left half** (`l` to `mid-1`).
4. Else, recursively search **right half** (`mid+1` to `r`).
5. Base Case: If `l > r`, return `-1` (element not found).
*/
int binarySearchRecursive(vector<int> &arr, int target, int l, int r)
{
    if (l > r)
        return -1; // Base case: Target not found

    int mid = l + (r - l) / 2;

    if (arr[mid] == target)
    {
        return mid; // Target found, return index
    }
    else if (arr[mid] > target)
    {
        return binarySearchRecursive(arr, target, l, mid - 1); // Search left half
    }
    else
    {
        return binarySearchRecursive(arr, target, mid + 1, r); // Search right half
    }
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6};

    int target = 5;

    cout << "Iterative Binary Search: Index = " << binarySearch(arr, target) << endl;
    cout << "Recursive Binary Search: Index = " << binarySearchRecursive(arr, target, 0, arr.size() - 1) << endl;

    return 0;
}
