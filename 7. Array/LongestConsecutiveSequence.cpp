#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

/*
Problem Statement:
-------------------
Given an unsorted array of integers, find the length of the **longest consecutive subsequence**.
A **consecutive subsequence** is a set of numbers that appear consecutively in increasing order.

Example 1:
----------
Input: arr = [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive subsequence is [1, 2, 3, 4] (length = 4).

Example 2:
----------
Input: arr = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]
Output: 9
Explanation: The longest consecutive subsequence is [0, 1, 2, 3, 4, 5, 6, 7, 8] (length = 9).
*/

/*
Naive Approach: Sorting + Linear Scan
-------------------------------------
1. Sort the array (O(n log n)).
2. Traverse the sorted array, counting consecutive elements.
3. If `arr[i]` is one more than `arr[i-1]`, increase count.
4. If `arr[i]` is the same as `arr[i-1]`, continue.
5. Else, reset count.

Time Complexity: **O(n log n)** (due to sorting)
Space Complexity: **O(1)**
*/
int LongestConsSequenceNaive(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return 0;

    sort(begin(arr), end(arr)); // Sorting the array
    int count = 1, res = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1]) // Ignore duplicates
            continue;

        if (arr[i] == (arr[i - 1] + 1))
        {
            count++;
            res = max(res, count);
        }
        else
        {
            count = 1;
        }
    }

    return res;
}

/*
Optimized Approach: Using Hash Set
-----------------------------------
1. Insert all elements in an **unordered_set** to allow O(1) lookups.
2. Traverse the set:
   - Check if the current number is the **start of a sequence** (i.e., `x-1` is not in the set).
   - If yes, iterate through consecutive numbers and count their length.
   - Update the max length found.

Time Complexity: **O(n)** (Each number is processed once)
Space Complexity: **O(n)** (Uses a hash set)
*/
int LongestConsSequence(vector<int> &arr)
{
    int n = arr.size();
    unordered_set<int> st(begin(arr), end(arr)); // Store all elements in a set for O(1) lookup
    int res = 0;

    for (int x : st)
    {
        if (st.find(x - 1) == st.end()) // Start a sequence if `x-1` is not found
        {
            int count = 0;
            int i = x;
            while (st.find(i) != st.end()) // Count consecutive numbers
            {
                count++;
                i++;
            }
            res = max(res, count);
        }
    }

    return res;
}

int main()
{
    vector<int> arr = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << "Length of the longest consecutive subsequence is " << LongestConsSequence(arr) << endl;
    return 0;
}

/*
Summary Table:
------------------------------------------------------
| Approach                     | Time Complexity | Space Complexity |
|------------------------------|----------------|------------------|
| Naive (Sorting + Scan)       | O(n log n)     | O(1)             |
| Optimized (Hash Set)         | O(n)           | O(n)             |
------------------------------------------------------
*/
