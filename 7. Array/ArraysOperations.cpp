#include <iostream>
using namespace std;

// Time Complexities:
// Insert : O(n) (Due to shifting elements after insertion)
// Search : O(n) for unsorted and O(log n) for sorted
// Delete : O(n) for unsorted (Due to shifting elements after deletion)
// Get ith element : O(1)
// Update ith element : O(1)
// Note: Insert at the end and delete from the end can be done in O(1) time

// Space Complexities:
// Insert : O(1) (No extra space used)
// Search : O(1) for sorted
// Delete : O(1) (No extra space used)
// Update : O(1)
// Get ith element : O(1)
// Note: Insert at the end and delete from the end can be done in O(1) time

// Function to perform search operation in the array
// Time Complexity: O(n) (Linear time to search the array)
int searchOperation(int arr[], int n, int x)
{
    // Loop through the array and check if element 'x' is found
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i; // Return index if element is found
        }
    }

    return -1; // Return -1 if element is not found
}

// Function to perform insert operation in the array
// Time Complexity: O(n) (Due to shifting elements after insertion)
void insertOperation(int arr[], int n, int x, int pos)
{
    int idx = pos - 1; // Adjusting position for 0-based index

    // Shift elements to the right to make space for the new element
    for (int i = n - 1; i >= idx; i--)
    {
        arr[i + 1] = arr[i];
    }

    arr[idx] = x; // Insert element at the specified position

    // Print the updated array
    for (int i = 0; i < n + 1; i++)
    {
        cout << arr[i] << " ";
    }

    return;
}

// Function to perform delete operation in the array
// Time Complexity: O(n) (Due to shifting elements after deletion)
void deleteOperation(int arr[], int n, int x)
{
    int i;

    // Find the element to be deleted
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
            break; // Exit loop if element is found
    }

    // If element is not found in the array
    if (i == n)
    {
        cout << "Element not found in array.";
        return;
    }

    // Shift elements to the left after deletion
    for (int j = i; j < n - 1; j++)
    {
        arr[j] = arr[j + 1];
    }

    return;
}

int main()
{
    int arr[6] = {10, 10, 14, 25, 86};    // Initialize array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate size of array
    cout << "Size: " << n << endl;        // Output the size of the array

    // Perform search operation and output the result
    cout << searchOperation(arr, n, 86) << endl; // Output: index of 86

    // Perform delete operation (86 will be deleted)
    deleteOperation(arr, n, 86);

    // Print the array after deletion
    for (int i = 0; i < n - 1; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
