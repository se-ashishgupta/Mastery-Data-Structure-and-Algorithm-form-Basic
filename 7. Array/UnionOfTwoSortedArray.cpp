#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*
Problem Statement:
------------------
Given two **sorted** arrays, we need to compute their **union** (a merged list of distinct elements from both arrays).

Approach 1: Merging Two Sorted Arrays (Efficient Approach)
----------------------------------------------------------
1. Use **two pointers** (`i` and `j`) to traverse `arr1` and `arr2` simultaneously.
2. If there are **duplicate** elements in either array, **skip** them.
3. Compare the current elements of both arrays:
   - If they are equal, add one instance to `res` and move both pointers.
   - If `arr1[i] < arr2[j]`, add `arr1[i]` to `res` and move `i` forward.
   - Otherwise, add `arr2[j]` to `res` and move `j` forward.
4. If any elements remain in either array, add them while skipping duplicates.
5. **Time Complexity:** O(n1 + n2) → Efficient linear merge approach.
6. **Space Complexity:** O(n1 + n2) → Stores distinct elements in a new array.
*/

vector<int> unionTwoSortedArray(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> res; // Result array to store the union
    int i = 0, j = 0;
    int n1 = arr1.size(), n2 = arr2.size();

    while (i < n1 && j < n2)
    {
        // Skip duplicate elements in arr1
        while (i < n1 - 1 && arr1[i] == arr1[i + 1])
            i++;
        // Skip duplicate elements in arr2
        while (j < n2 - 1 && arr2[j] == arr2[j + 1])
            j++;

        // If both elements are equal, add one instance and move both pointers
        if (arr1[i] == arr2[j])
        {
            res.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            res.push_back(arr1[i]);
            i++;
        }
        else
        {
            res.push_back(arr2[j]);
            j++;
        }
    }

    // Add remaining elements from arr1 while avoiding duplicates
    while (i < n1)
    {
        while (i < n1 - 1 && arr1[i] == arr1[i + 1])
            i++;
        res.push_back(arr1[i]);
        i++;
    }

    // Add remaining elements from arr2 while avoiding duplicates
    while (j < n2)
    {
        while (j < n2 - 1 && arr2[j] == arr2[j + 1])
            j++;
        res.push_back(arr2[j]);
        j++;
    }

    return res;
}

/*
Approach 2: Using a Set (Simpler but Less Efficient)
-----------------------------------------------------
1. **Insert all elements from both arrays** into a `set`, which automatically removes duplicates.
2. Convert the `set` back into a `vector` and return the result.
3. **Time Complexity:** O(n1 log n1 + n2 log n2) due to insertion in a `set` (logarithmic complexity).
4. **Space Complexity:** O(n1 + n2) (due to `set` storage).
*/

vector<int> unionTwoSortedArrayUsingSet(vector<int> &arr1, vector<int> &arr2)
{
    set<int> st; // Set to store unique elements
    for (int x : arr1)
        st.insert(x);
    for (int x : arr2)
        st.insert(x);

    // Convert the set back into a vector
    vector<int> res(st.begin(), st.end());

    return res;
}

int main()
{
    vector<int> arr1{-8, -3, -3, -2, 0, 1, 2, 2, 6};
    vector<int> arr2{-9, -9, 0};

    // Using the efficient approach (two-pointer technique)
    vector<int> result1 = unionTwoSortedArray(arr1, arr2);
    cout << "Union using two-pointer approach: ";
    for (int x : result1)
    {
        cout << x << " ";
    }
    cout << endl;

    // Using the set-based approach
    vector<int> result2 = unionTwoSortedArrayUsingSet(arr1, arr2);
    cout << "Union using set approach: ";
    for (int x : result2)
    {
        cout << x << " ";
    }

    return 0;
}
