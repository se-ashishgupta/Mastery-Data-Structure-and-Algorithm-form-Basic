#include <iostream>
using namespace std;

// Function to find the largest element in an array
// Time Complexity: O(n) (Linear time due to a single pass through the array)
// Auxiliary Space: O(1) (No extra space used, only a constant amount of space for the 'max' variable)
int largestElement(int arr[], int n)
{
    int max = arr[0]; // Initialize 'max' as the first element of the array

    // Loop through the array starting from the second element
    for (int i = 1; i < n; i++)
    {
        // If the current element is larger than 'max', update 'max'
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // Return the largest element found
    return max;
}

int main()
{
    int arr[] = {10, 50, 480, 96, 455};   // Initialize the array of integers
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    // Call the 'largestElement' function and print the result with a descriptive string
    cout << "Largest Element: " << largestElement(arr, n) << endl; // Output: 480 (largest element in the array)

    return 0;
}
