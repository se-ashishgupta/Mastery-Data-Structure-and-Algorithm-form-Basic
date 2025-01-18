#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to perform right rotation of an array by one position (Naive Approach)
// Time Complexity: O(n) (Linear - single loop to shift elements)
// Auxiliary Space: O(1) (Only one variable 'f' used for storage)
void RightRotateAnArrayNaive(vector<int> &arr)
{
    int n = arr.size(); // Get the size of the array

    // Step 1: Store the last element of the array
    int f = arr[n - 1]; // Variable 'f' stores the last element temporarily

    // Step 2: Shift all elements of the array from right to left
    // Starting from the second-last element (index n-2) to the first element (index 0)
    for (int i = n - 1; i > 0; i--) // Loop decreases 'i' each time
    {
        arr[i] = arr[i - 1]; // Move the element at 'i-1' to position 'i'
    }

    // Step 3: Place the stored last element in the first position
    arr[0] = f; // The last element 'f' is assigned to the first index (rotation complete)
}

int main()
{
    // Example input array
    vector<int> arr = {1, 2, 3, 4, 5}; // Original array: {1, 2, 3, 4, 5}

    // Call the function to perform one right rotation
    RightRotateAnArrayNaive(arr);

    // Print the rotated array to verify the result
    for (int x : arr) // Enhanced for-loop to iterate over each element in the array
    {
        cout << x << " "; // Print each element followed by a space
    }

    return 0; // Exit the program successfully
}
