#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to move all zeros in the array to the end (in-place)
// Time Complexity: O(n) (Linear time because we traverse the array once)
// Auxiliary Space: O(1) (No extra space except for a few variables)
void moveZerosToEnd(vector<int> &arr)
{
    int n = arr.size(); // Get the size of the array
    int idx = 0;        // Pointer to track the position of the next non-zero element

    // Step 1: Loop through the array
    for (int i = 0; i < n; i++)
    {
        // Step 2: If the current element is non-zero, move it to the front
        if (arr[i] != 0)
        {
            swap(arr[idx++], arr[i]); // Swap the element at 'idx' with the current element
        }
    }
    // After the loop, all non-zero elements will be moved to the front of the array
    // The zeros will naturally be pushed to the end due to the swaps
}

int main()
{
    // Example input array (with zeros in between)
    vector<int> arr = {8, 5, 0, 10, 0, 20};

    // Call the function to move zeros to the end of the array
    moveZerosToEnd(arr);

    // Step 3: Print the array after moving the zeros to the end
    for (int x : arr) // Loop through the modified array and print each element
    {
        cout << x << " "; // Print each element followed by a space
    }

    return 0; // Exit the program successfully
}
