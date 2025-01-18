#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to left rotate the array by one position using a naive approach
// Time Complexity: O(n) (Linear, as we are traversing the array once)
// Auxiliary Space: O(1) (No extra space except for a few variables)
void leftRotateAnArraydNaive(vector<int> &arr)
{
    int n = arr.size(); // Get the size of the array
    int f = arr[0];     // Store the first element, which will be moved to the end

    // Step 1: Shift all the elements of the array to the left by one position
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i]; // Move the current element to the previous position
    }

    // Step 2: Place the first element at the end of the array
    arr[n - 1] = f; // Move the stored first element to the last position
}

int main()
{
    // Example input array
    vector<int> arr = {1, 2, 3, 4, 5};

    // Step 3: Call the function to left rotate the array by one position
    leftRotateAnArraydNaive(arr);

    // Step 4: Print the modified array after left rotation
    for (int x : arr) // Loop through the array and print each element
    {
        cout << x << " "; // Print each element followed by a space
    }

    return 0; // Exit the program successfully
}
