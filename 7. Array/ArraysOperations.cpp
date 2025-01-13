#include <iostream>
using namespace std;

// Time Complaxities
// Insert : O(n)
// Search : O(n) for unsortd and O(logn) for sorted
// Delete : O(n) for unsorted
// Get ith element : O(1);
// Upadate ith element : o(1)
// Note: Insert at the end and elete from the end can be done in o(1) time

// Space Complaxities
// Insert : O(1)
// Search : O(1) for sorted
// Delete : O(1)
// Upadate : O(1)
// Get ith element : O(1);
// Note: Insert at the end and elete from the end can be done in o(1)

int searchOperation(int arr[], int n, int x)
{

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }

    return -1;
}

void insertOperation(int arr[], int n, int x, int pos)
{

    int idx = pos - 1;
    for (int i = n - 1; i >= idx; i--)
    {
        arr[i + 1] = arr[i];
    }

    arr[idx] = x;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return;
}

void deleteOperation(int arr[], int n, int x)
{

    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
            break;
    }

    if (i == n)
    {
        cout << "Element not found in array.";
        return;
    }

    for (int j = i; j < n; j++)
    {
        arr[j] = arr[j + 1]; // Shift elements to the left
    }

    return;
}
int main()
{

    int arr[6] = {10, 10, 14, 25, 86};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Size: " << n << endl;
    cout << searchOperation(arr, n, 86) << endl;
    // insertOperation(arr, n, 90, 2);
    deleteOperation(arr, n, 86);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}