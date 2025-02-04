#include <iostream>
#include <vector>
using namespace std;

/*
Problem Statement:
------------------
Given an array `nums` containing only 0s, 1s, and 2s, sort the array in-place
so that all 0s come first, followed by all 1s, and then all 2s.
You must solve this problem in **O(n) time complexity and O(1) space complexity**.

Approach: Dutch National Flag Algorithm (Three-Way Partitioning)
----------------------------------------------------------------
1. We use **three pointers**:
   - `low`: Points to the position where the next `0` should be placed.
   - `mid`: Scans through the array.
   - `high`: Points to the position where the next `2` should be placed.
2. We traverse `nums` using `mid`:
   - If `nums[mid] == 0`, swap `nums[low]` and `nums[mid]`, then increment `low` and `mid`.
   - If `nums[mid] == 1`, just increment `mid` (correct position).
   - If `nums[mid] == 2`, swap `nums[mid]` and `nums[high]`, then decrement `high`.
3. **Time Complexity:** O(n) (each element is processed at most once).
4. **Space Complexity:** O(1) (in-place sorting).

*/

void sortColors(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            // Swap current 0 to the position of `low`
            swap(nums[low], nums[mid]);
            low++; // Move `low` pointer forward
            mid++; // Move `mid` pointer forward
        }
        else if (nums[mid] == 1)
        {
            mid++; // 1 is in the correct place, just move `mid` forward
        }
        else
        {
            // Swap current 2 to the position of `high`
            swap(nums[mid], nums[high]);
            high--; // Move `high` pointer backward
            // Do NOT increment `mid` because swapped value could be 0 or 1
        }
    }
}

int main()
{
    vector<int> arr{2, 0, 1, 1, 0, 2}; // Input array
    sortColors(arr);                   // Sorting using Dutch National Flag algorithm

    // Print sorted array
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
