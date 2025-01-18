#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to left rotate an array by one position
// Time Complexity: O(n)
// Auxiliary Space: O(1)
void leftRotateAnArrayByOne(vector<int> &arr)
{
    int n = arr.size(); // Get the size of the array
    int f = arr[0];     // Store the first element in a temporary variable

    // Shift all elements one position to the left
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i]; // Move element `i` to the previous index
    }

    // Place the first element at the last position
    arr[n - 1] = f;
}

// Naive method to left rotate an array by `d` positions
// Calls the `leftRotateAnArrayByOne` function `d` times
// Time Complexity: O(d * n)
// Auxiliary Space: O(1)
void leftRotateAnArrayByDNaive(vector<int> &arr, int d)
{
    for (int i = 0; i < d; i++) // Perform `d` left rotations
    {
        leftRotateAnArrayByOne(arr); // Rotate the array by one position
    }
}

// Efficient method to left rotate an array by `d` positions
// Time Complexity: O(n)
// Auxiliary Space: O(d)
void leftRotateAnArrayByDEfficient(vector<int> &arr, int d)
{
    int n = arr.size(); // Get the size of the array
    d = d % n;          // Handle cases where `d > n` (ignores over-rotation)

    // Step 1: Create a temporary array to store the first `d` elements
    vector<int> temp(arr.begin(), arr.begin() + d);

    // Step 2: Shift the remaining elements to the left
    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }

    // Step 3: Copy the elements from the temporary array to the end
    for (int i = 0; i < d; i++)
    {
        arr[n - d + i] = temp[i];
    }
}

// Helper function to reverse a portion of the array
// Time Complexity: O(end - start + 1)
// Auxiliary Space: O(1)
void reverse(vector<int> &arr, int start, int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]); // Swap the elements at `start` and `end`
        start++;
        end--;
    }
}

// Reverse Algorithm for left rotating an array by `d` positions
// Time Complexity: O(n)
// Auxiliary Space: O(1)
void leftRotateAnArrayByDReverse(vector<int> &arr, int d)
{
    int n = arr.size(); // Get the size of the array
    d = d % n;          // Handle cases where `d > n` (ignores over-rotation)

    // Step 1: Reverse the first `d` elements
    reverse(arr, 0, d - 1);

    // Step 2: Reverse the remaining `n - d` elements
    reverse(arr, d, n - 1);

    // Step 3: Reverse the entire array
    reverse(arr, 0, n - 1);
}

int main()
{
    // Initialize an array
    vector<int> arr = {1, 2, 3, 4, 5};

    // Call the efficient method to left rotate the array by 4 positions
    leftRotateAnArrayByDEfficient(arr, 2);

    // Alternatively, use the reverse method
    // leftRotateAnArrayByDReverse(arr, 4);

    // Print the rotated array
    for (int x : arr)
    {
        cout << x << " "; // Output each element with a space
    }

    return 0; // Exit the program successfully
}
