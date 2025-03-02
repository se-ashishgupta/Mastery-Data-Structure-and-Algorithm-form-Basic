#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
Problem Statement:
-------------------
Given an **N x N** matrix, rotate it **90 degrees clockwise** **in place**.

Example 1:
----------
Input:
arr = [[1, 2, 3],
       [4, 5, 6],
       [7, 8, 9]]

Output:
arr = [[7, 4, 1],
       [8, 5, 2],
       [9, 6, 3]]

Example 2:
----------
Input:
arr = [[5,  1,  9,  11],
       [2,  4,  8,  10],
       [13, 3,  6,  7],
       [15, 14, 12, 16]]

Output:
arr = [[15, 13, 2,  5],
       [14, 3,  4,  1],
       [12, 6,  8,  9],
       [16, 7,  10, 11]]
*/

/*
Naive Approach 1: Extra Array + Reverse Filling
-----------------------------------------------
1. Create a **new result matrix**.
2. Traverse each column from **bottom to top** and store it in a row of the new matrix.
3. Return the new matrix.

Time Complexity: **O(N^2)**
Space Complexity: **O(N^2)** (Extra matrix)
*/
vector<vector<int>> rotateImageNaive1(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<vector<int>> res;

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = n - 1; j >= 0; j--)
        {
            temp.push_back(arr[j][i]); // Reverse column into row
        }
        res.push_back(temp);
    }

    return res;
}

/*
Naive Approach 2: Using a New Matrix
-------------------------------------
1. Create an **empty result matrix**.
2. Assign `res[j][n - 1 - i] = arr[i][j]` for each element.
3. Return the result.

Time Complexity: **O(N^2)**
Space Complexity: **O(N^2)**
*/
vector<vector<int>> rotateImageNaive2(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<vector<int>> res(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[j][n - 1 - i] = arr[i][j]; // Move row to rotated column
        }
    }

    return res;
}

/*
Optimized Approach: In-Place Rotation
-------------------------------------
1. **Transpose the matrix**: Swap `arr[i][j]` with `arr[j][i]`.
2. **Reverse each row**: Swap `arr[i][j]` with `arr[i][n-1-j]`.

Time Complexity: **O(N^2)**
Space Complexity: **O(1)** (In-place modification)
*/
void rotateImageOptimize(vector<vector<int>> &arr)
{
    int n = arr.size();

    // Step 1: Transpose the matrix (convert rows to columns)
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    // Step 2: Reverse each row
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            swap(arr[i][j], arr[i][n - 1 - j]); // Swap elements in each row
        }
    }
}

int main()
{
    vector<vector<int>> arr = {{5, 1, 9, 11},
                               {2, 4, 8, 10},
                               {13, 3, 6, 7},
                               {15, 14, 12, 16}};

    rotateImageOptimize(arr);

    for (auto x : arr)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Summary Table:
-------------------------------------------------
| Approach            | Time Complexity | Space Complexity |
|---------------------|----------------|------------------|
| Naive (Extra Array) | O(N^2)         | O(N^2)           |
| Optimized (In-Place)| O(N^2)         | O(1)             |
-------------------------------------------------
*/
