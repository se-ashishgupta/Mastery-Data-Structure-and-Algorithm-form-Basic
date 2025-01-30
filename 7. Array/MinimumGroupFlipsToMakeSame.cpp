#include <iostream>
#include <vector>
using namespace std;

/*
Problem Statement:
------------------
Given a binary array (containing only 0s and 1s), we need to make all elements the same
by flipping consecutive groups of either 0s or 1s. The goal is to find the minimum number
of flips required and print the ranges to be flipped.

Efficient Approach:
-------------------
1. Instead of counting and flipping both groups (0s and 1s), we only flip the second
   occurring group. This always gives the minimum number of flips.
2. Traverse the array:
   - If the current element is different from the previous one, a new group starts.
   - If this new group is not the same as the first element of the array, it needs to be flipped.
   - Print the start index of this new group.
   - When encountering the next change, print the previous index to mark the end of the flipping range.
3. Handle the last group separately if needed.
4. **Time Complexity:** O(n), as we traverse the array once.
5. **Space Complexity:** O(1), as no extra space is used.
*/

void minimumGroupFlipMakeSameEfficient(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        // Detect a transition (change in value)
        if (arr[i] != arr[i - 1])
        {
            // Start of a new group different from the first element
            if (arr[i] != arr[0])
            {
                cout << "From " << i << " to ";
            }
            // End of a group that needs flipping
            else
            {
                cout << i - 1 << endl;
            }
        }
    }

    // If the last group needs flipping, print its end index
    if (arr[n - 1] != arr[0])
    {
        cout << n - 1 << endl;
    }
}

int main()
{
    vector<int> arr{1, 1, 0, 0, 0, 1, 0, 0, 1, 0};
    minimumGroupFlipMakeSameEfficient(arr);

    return 0;
}
