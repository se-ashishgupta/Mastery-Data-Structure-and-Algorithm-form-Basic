#include <iostream>
#include <vector>
using namespace std;

// Function to reverse the elements of the array
// Time Complexity: O(n) (Linear, since we traverse the array once)
// Auxiliary Space: O(1) (In-place operation, no extra space is used)
void reverseArray(vector<int> &arr)
{
    int n = arr.size();         // Get the size of the array
    int start = 0, end = n - 1; // Initialize two pointers: start at the beginning and end at the last element

    // Loop until the start pointer is less than the end pointer
    while (start < end)
    {
        // Swap the elements at the start and end pointers
        // Option 1: Using the built-in swap function
        // swap(arr[start], arr[end]);

        // Option 2: Using a temporary variable to manually swap
        int temp = arr[start]; // Store the start element in a temporary variable
        arr[start] = arr[end]; // Assign the value at the end pointer to the start position
        arr[end] = temp;       // Assign the stored value from temp to the end position

        // Move the pointers closer to the middle
        start++;
        end--;
    }
}

int main()
{
    // Initialize a vector (dynamic array) with some elements
    vector<int> arr = {10, 54, 1, 25, 89, 60};

    // Call the function to reverse the array
    reverseArray(arr);

    // Print the reversed array
    for (int x : arr)
    {
        cout << x << " "; // Output each element of the array with a space
    }
    return 0; // Exit the program successfully
}
