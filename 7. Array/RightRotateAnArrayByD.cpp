#include <iostream>
#include <vector>
#include <algorithm> // For using the reverse function
using namespace std;

// Function to right rotate an array by one position
// Time Complexity: O(n) (Traverse the entire array once)
// Auxiliary Space: O(1) (In-place rotation)
void RightRotateAnArrayByOne(vector<int> &arr)
{
    int n = arr.size(); // Get the size of the array
    int f = arr[n - 1]; // Store the last element in a temporary variable

    // Shift all elements one position to the right
    for (int i = n - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1]; // Move the previous element to the current position
    }
    arr[0] = f; // Place the last element at the first position
}

// Naive method to right rotate an array by `d` positions
// Calls the `RightRotateAnArrayByOne` function `d` times
// Time Complexity: O(d * n) (For each of the `d` rotations, we traverse the array)
// Auxiliary Space: O(1) (In-place rotation)
void RightRotateAnArrayByDNaive(vector<int> &arr, int d)
{
    for (int i = 0; i < d; i++) // Perform right rotation `d` times
    {
        RightRotateAnArrayByOne(arr); // Rotate the array by one position
    }
}

// Efficient method to right rotate an array by `d` positions
// Time Complexity: O(n) (Single traversal of the array)
// Auxiliary Space: O(d) (Temporary array to store `d` elements)
void RightRotateAnArrayByDEfficient(vector<int> &arr, int d)
{
    int n = arr.size(); // Get the size of the array
    d = d % n;          // Handle cases where `d > n` (ignores over-rotation)

    // Step 1: Create a temporary array to store the last `d` elements
    vector<int> temp(arr.end() - d, arr.end());

    // Step 2: Shift the remaining elements in the array to the right
    for (int i = n - d - 1; i >= 0; i--)
    {
        arr[i + d] = arr[i]; // Move element at `i` to the `i + d` position
    }

    // Step 3: Copy the elements from the temporary array to the beginning
    for (int i = 0; i < d; i++)
    {
        arr[i] = temp[i];
    }
}

// Reverse Algorithm for right rotation by `d` positions
// Time Complexity: O(n) (Three reversals, each traversing part of the array)
// Auxiliary Space: O(1) (In-place rotation)
void RightRotateAnArrayByDReverse(vector<int> &arr, int d)
{
    int n = arr.size(); // Get the size of the array
    d = d % n;          // Handle cases where `d > n` (ignores over-rotation)

    // Reverse the entire array
    reverse(arr.begin(), arr.end());

    // Reverse the first `d` elements
    reverse(arr.begin(), arr.begin() + d);

    // Reverse the remaining `n - d` elements
    reverse(arr.begin() + d, arr.end());
}

int main()
{
    // Initialize an array
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    // Call the efficient method to right rotate the array by 3 positions
    RightRotateAnArrayByDEfficient(arr, 3);

    // Alternatively, use the reverse method
    // RightRotateAnArrayByDReverse(arr, 3);

    // Print the rotated array
    for (int x : arr)
    {
        cout << x << " "; // Output each element with a space
    }

    return 0; // Exit the program successfully
}
