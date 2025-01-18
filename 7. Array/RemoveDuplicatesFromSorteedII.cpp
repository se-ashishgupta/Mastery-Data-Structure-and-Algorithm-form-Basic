#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to remove duplicates from a sorted array
// allowing each element to appear at most twice.
// Time Complexity: O(n) (Linear, as we process each element once)
// Auxiliary Space: O(1) (No extra space used except for the index variable)
void removeDuplicatedII(vector<int> &arr)
{
    int n = arr.size(); // Get the size of the array
    int idx = 1;        // Index to track the position where the next valid element should go

    // Loop through the array starting from the second element
    for (int i = 1; i < n; i++) // i is used to traverse the array
    {
        // Check if the current element is the same as the one two positions before the current element
        // We want to allow at most two duplicates, so:
        if (idx == 1 || arr[i] != arr[idx - 2])
        {
            // If it's a valid element (not the third duplicate), move it to the `idx` position
            // This places the current element in its new position and increments `idx`
            swap(arr[idx++], arr[i]);
        }
    }
}

int main()
{
    // Initialize the input array (sorted array with duplicates)
    vector<int> arr = {1, 1, 1, 2, 2, 3}; // Original array: {1, 1, 1, 2, 2, 3}

    // Call the function to remove duplicates, allowing at most two occurrences of each element
    removeDuplicatedII(arr);

    // Print the resulting array after removing duplicates
    for (int x : arr) // Loop through the array and print each element
    {
        cout << x << " "; // Output the array with the allowed duplicates
    }

    return 0; // Exit the program successfully
}
